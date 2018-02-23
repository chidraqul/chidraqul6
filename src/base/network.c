//chidraqul6 made by ChillerDragon
//ChillerDragon copyright (c)
//started development 2017

#include "network.h"

#ifdef __cplusplus
extern "C" {
#endif

    
    void *get_in_addr(struct sockaddr *sa)
    {
        if (sa->sa_family == AF_INET) {
            return &(((struct sockaddr_in*)sa)->sin_addr);
        }
        
        return &(((struct sockaddr_in6*)sa)->sin6_addr);
    }
     

#ifdef __cplusplus
}
#endif
