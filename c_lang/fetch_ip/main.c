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


int main() {
    char hostBuffer[256];
    char *IPBuffer;
    struct hostent *host_entry;
    int hostname;

    hostname = gethostname(hostBuffer, sizeof(hostBuffer));

    if (hostname == -1) {
        perror("gethostname");
        exit(1);
    }


    host_entry = gethostbyname(hostBuffer);

    if (host_entry == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    IPBuffer = inet_ntoa(*((struct in_addr*) host_entry->h_addr_list[0]));

    printf("Hostname: %s\n", hostBuffer);
    printf("Host IP: %s\n", IPBuffer);

    return 0;

}

