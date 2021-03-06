#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <iostream>


int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cout << "Usage: -p [PORT]\n";
        return -1;
    }

    int port;
    for(int i = 1; i < argc; ++i) {
        if(strcmp("-p", argv[i]) == 0) {
            if(i + 1 == argc) {
                std::cout << "Usage: -p [PORT]\n";
                return -1;
            }
            port = atoi(argv[++i]);
        }
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr("192.168.43.213");

    int serveur = socket(AF_INET, SOCK_STREAM, 0);
    if(serveur == -1) {
        std::cerr << "Erreur: " << strerror(errno) << '\n';
        return -1;
    }
    if(connect(serveur, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1) {
        std::cerr << "Erreur: " << strerror(errno) << '\n';
        return -1;
    }


    send(serveur, "Hello", 5, MSG_DONTWAIT);
    char buffer[1107];
    bzero(buffer, 1107);
    recv(serveur, buffer, 1107, 0);
    std::cout << buffer << '\n';

    close(serveur);
    return 0;
}