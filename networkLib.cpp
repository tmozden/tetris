/*
 * Author Travis Mozden
 * Tech Hacks 2013
 * network library for bro tetris
*/

#include "networkLib.h"


NetworkManager::NetworkManager(){

}

void NetworkManager::prepListeningSocket(){

    //initilize variables and structs
    servStructSize = sizeof(servStruct);
    clientStructSize = sizeof(clientStruct);
    
    //zero out struct
	bzero((char *) &servStruct, sizeof(servStruct)); 
	bzero((char *) &clientStruct, sizeof(clientStruct)); 
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	if (sockfd < 0){
		perror("ERROR opening socket");
		exit(1); 
	}
	
	// create destination
	servStruct.sin_family = AF_INET;
	servStruct.sin_addr.s_addr = INADDR_ANY;
	servStruct.sin_port = htons(0);
	
	errorCheck = bind(sockfd, (struct sockaddr*) &servStruct, servStructSize);
	if(errorCheck < 0){
		perror("problem with bind");
		exit(1); 
	}
	
	
	// print port number
	errorCheck = getsockname(sockfd, (struct sockaddr*) &servStruct, &servStructSize);
	if(errorCheck < 0){
		perror("problem getsockname");
		exit(1); 
	}
	printf("%d\n", ntohs(servStruct.sin_port));
	fflush(stdout);
	
		// listen
    errorCheck = listen(sockfd, 1);
    if (errorCheck < 0) { 
    	perror("problem with listen"); 
    	exit(1); 
    }

}

int NetworkManager::acceptConnection(){
    
    //accept client connection
	clisockfd = accept(sockfd, (struct sockaddr*) &clientStruct, &clientStructSize);
    if (clisockfd < 0) { 
		perror("problem in accept"); 
		exit(1); 
	}
	
	return clisockfd;
}

int NetworkManager::connectToServer(char * host, char * portNum){

    memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	
	if ((rv = getaddrinfo(host, portNum, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}
	
	// loop through all the results and connect to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			perror("client: socket");
			continue;
		}

		if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("client: connect");
			continue;
		}
		break;
	}
    return sockfd;
}

