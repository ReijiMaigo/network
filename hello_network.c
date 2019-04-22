#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(void)
{
    int status;
    struct addrinfo hints;
    struct addrinfo *servinfo;
    struct sockaddr_in *sin;
    char ip4[INET_ADDRSTRLEN];

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
    }
    printf("connoname: %s\n", servinfo->ai_canonname);
    sin = (struct sockaddr_in*) &(servinfo->ai_addr);

    inet_ntop(AF_INET, &(sin->sin_addr), ip4, INET_ADDRSTRLEN);

    printf("servinfo addr: %s", ip4);

    freeaddrinfo(servinfo);
    return 0;
}
