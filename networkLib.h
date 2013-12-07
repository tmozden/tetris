 /*
 * Author Travis Mozden
 * Tech Hacks 2013
 * network library for bro tetris
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <errno.h>

#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>




class NetworkManager {

    private:
    struct sockaddr_in servStruct, clientStruct;
    struct addrinfo hints, *servinfo, *p;
    socklen_t servStructSize, clientStructSize;
    int sockfd, clisockfd, errorCheck, rv;
    

    public:
    NetworkManager();
    int acceptConnection();
    void prepListeningSocket();
    int connectToServer(char * host, char * portNum);
    
};
