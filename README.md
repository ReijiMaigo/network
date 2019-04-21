# network
note
[Ethernet[IP[UDP[TFTP[DATA]]]]]

Application Layer - telnet, ftp, etc
Host-to-Host Transport Layer - TCP, UDP
Internet Layer - IP and routing
Network Access Layer - Ethernet, wifi

htons() host to network short
htonl() host to network long
ntohs() network to host short
ntohl() network to host long

struct addrinfo{
    int             ai_flags;       // AI_PASSIVE, AI_CANONAME, etc
    int             ai_family;      // AF_INET, AF_INET6, AF_UNSPEC
    int             ai_socktype;  // SOCK_STREAM, SOCK_DGRAM
    int             ai_protocol;    // use 0 for 'any'
    size_t          ai_addrlen;     // size of ai_addr in bytes
    struct sockaddr *ai_addr;       // struct sockaddr_in or _in6
    char            *ai_canonname;  // full canonical hostname
    struct addrinfo *ai_next;       // linked list, next node
}

struct sockaddr {
    unsigned short  sa_family;      // addr family, AF_xxx
    char            sa_data[14];    // 14 bytes of protocol address
}

*can be translated to sockaddr_in as well*

struct sockaddr_in {
    short int           sin_family;
    unsigned short int  sin_port;
    struct in_addr      sin_addr;
    unsigned char       sin_zero[8];
}

*IPV6 uses sockaddr_in6 and in6_addr*
*use sockaddr_storage to store ipv4 or ipv6*

inet_pton() : presentation/printable to network (ip char to in_addr structure)
inet_pthon(<AF_INET or AF_INET6>, <IP in char>, <in_addr structure>)

or inet_aton() : same but obsolete
inet_ntop() : reverse it
inet_ntop(AF_INET, &(sa.sin_addr), ip4, INET_ADDRSTRLEN);

int socket(int domain, int type, int protocol) - Get the File Descriptor
@arg domain : PF_INET or PF_INET6
@arg type : SOCK_STREAM or SOCK_DGRAM
@protocol : can set to 0 (find out) 

int bind(int sockfd, struct sockaddr *my_addr, int addrlen); - Inform the port for the specific ip address
port below 1024 are reserved

int connect(int sockfd, struct sockaddr *serv_addr, int addrlen); - connect to destination
@arg sockfd : file descriptor
@arg serv_addr : destination address
@arg addrlen : destination address length
*binding is not required for connect(), we don't need to know our local port*

int listen(int sockfd, int backlog); - listen to connection
@arg backlog : number of connections allowed on the incoming queue
*binding is required*





