
#include "Client.h"

int main(int argc, char** argv) {

    if(argc < 3){
        perror("must specify host and port");
        exit(1);
    }
    
    NetworkManager* networkManager = new NetworkManager();
    
    int connectionFd = networkManager->connectToServer(argv[1], argv[2]);
    
    char test[100];
    read(connectionFd, test, 100);
    printf(test);
    
    delete networkManager;
    


}
