//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#if defined(__APPLE__) || defined(__linux__)

#ifdef __cplusplus
extern "C" {
#endif

#include "networking_server_osx.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

#include "../base/system.h"
#include "../base/network.h"
#include "server.h"

#define BACKLOG 10     // how many pending connections queue will hold

int ServerTick = 0; //TODO: remove this because it is only for debugging
ServerSettings srv_settings;
char aPort[16];
    
unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

void sigchld_handler(int s)
{
    // waitpid() might overwrite errno, so we save and restore it:
    int saved_errno = errno;
    
    while(waitpid(-1, NULL, WNOHANG) > 0);
    
    errno = saved_errno;
}


// get sockaddr, IPv4 or IPv6:
/*
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
    
    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}
*/

int main(void)
{
    char aBuf[16];
    InitServer(&srv_settings);
    str_format(aPort, sizeof(aPort), "%d", srv_settings.Port);
    
    int sockfd, new_fd;  // listen on sock_fd, new connection on new_fd
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr; // connector's address information
    socklen_t sin_size;
    struct sigaction sa;
    int yes=1;
    char s[INET6_ADDRSTRLEN];
    int rv;
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; // use my IP
    
    if ((rv = getaddrinfo(NULL, aPort, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }
    
    // loop through all the results and bind to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                             p->ai_protocol)) == -1) {
            perror("server: socket");
            continue;
        }
        
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
                       sizeof(int)) == -1) {
            perror("setsockopt");
            exit(1);
        }
        
        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("server: bind");
            continue;
        }
        
        break;
    }
    
    freeaddrinfo(servinfo); // all done with this structure
    
    if (p == NULL)  {
        fprintf(stderr, "server: failed to bind\n");
        exit(1);
    }
    
    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }
    
    sa.sa_handler = sigchld_handler; // reap all dead processes
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }
    
    printf("server: waiting for connections on port %s ...\n", aPort);
    
    while(1) {  // main accept() loop
        //sleep(1); //be nice c:
        printf("tick=%d\n", ServerTick++);
        //server runs fine till:
        //Tick=~16k -> it gets stuck for 20 seconds and then runs agian
        //Tick=~32k -> gets stucked same way and then runs agian
        //Tick=~49k -> i guess u get it ...
        
        
        sin_size = sizeof their_addr;
        new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
        
        if (new_fd == -1) {
            perror("accept");
            continue;
        }
         
        
        inet_ntop(their_addr.ss_family,
                  get_in_addr((struct sockaddr *)&their_addr),
                  s, sizeof s);
        //printf("server: got connection from %s\n", s);
        
        //if (!fork()) { // this is the child process
            //close(sockfd); // child doesn't need the listener
            
            
            //=== RECIVE ===
            memset(aBuf, 0, sizeof(aBuf));
            recv(new_fd, aBuf, sizeof(aBuf), 0);
            printf("Client [%s]\n", aBuf);
            //printf("[debug] send\n");
            
            //=== PROCESS data ===   (handelt in server.cpp)
            //srand(mix(clock(), time(NULL), getpid())); //new rand needed every tick because fork
            //str_format(aBuf, sizeof(aBuf), "%d", rand() % 3 - 1);
            //Test(); //works
            MainDataJuggeling(aBuf);
            //printf("[debug] survived data juggle\n");
            
            
            //=== SEND ===
            if (send(new_fd, aBuf, sizeof(aBuf), 0) == -1)
            {
                perror("send");
            }
            else
            {
                printf("Server [%s]\n", aBuf);
            }
            
            close(new_fd);
            //exit(0);
        //}
        //close(new_fd);  // parent doesn't need this
    }
    
    return 0;
}
    
#ifdef __cplusplus
}
#endif


#endif
