//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017


#if defined(__APPLE__) || defined(__linux__)


#include "networking_client_osx.h"
    
/*
 ** client.c -- a stream socket client demo
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
    
#include "../base/system.h"
#include "../base/network.h"
#include "net_client.h"
#include "world.h"
#include "controls.h"
#include "render.h"

#define PORT "4200" // the port client will be connecting to

#define MAXDATASIZE 100 // max number of bytes we can get at once

int NetworkMain(ClientSettings * pSettings, CPlayer& player, CPlayer& player2)
{
    int sockfd, numbytes;
    char aBuf[MAXDATASIZE];
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];
    
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    if ((rv = getaddrinfo(pSettings->aServerIP, pSettings->aServerPort, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return -1;
    }
    
    // loop through all the results and connect to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                             p->ai_protocol)) == -1) {
            perror("client: socket");
            continue;
        }
        
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("client: connect");
            close(sockfd);
            continue;
        }
        
        break;
    }
    
    if (p == NULL) {
        fprintf(stderr, "client: failed to connect\n");
        return -1;
    }
    
    inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
              s, sizeof s);
    //printf("client: connecting to %s\n", s);
    
    freeaddrinfo(servinfo); // all done with this structure
    
    char aClientReply[16] = "-1_0_0_0_0"; //idk initital client message
    
    while (1)
    {
        /****************
         *   networking *
         ****************/
        
        send(sockfd, aClientReply, sizeof(aClientReply), 0);
        printf("\n\n\n\n\n\n\n  sending reply: %s ", aClientReply);
        
        if ((numbytes = recv(sockfd, aBuf, MAXDATASIZE-1, 0)) == -1) {
            perror("recv");
            exit(1);
        }
        aBuf[numbytes] = '\0';
        
        
        //str_format(aClientReply, sizeof(aClientReply), "%s", SuckNetwork(aBuf, player, player2));
        
        SuckNetwork(aBuf, player, player2, aClientReply); //side effect should work better than return str
        
        /****************
         *   client     *
         ****************/
        
        HandleInputs(player); //creates LastInpDirX
        player.OnTick(); //uses LastInpDirX to keep moving in fall
    }
    
    //printf("client: received '%s'\n",aBuf);
    //int recv_pos = atoi(aBuf);
    char * pBuf = &aBuf[0];
    
    //PumpNetwork(pBuf);
    
    close(sockfd);
    
    return -1;
}

    
#endif

