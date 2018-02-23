//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#ifndef NETWORK_H
#define NETWORK_H

#include <arpa/inet.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    // get sockaddr, IPv4 or IPv6:
    void *get_in_addr(struct sockaddr *sa);


#ifdef __cplusplus
}
#endif
    
#endif // NETWORK_H
