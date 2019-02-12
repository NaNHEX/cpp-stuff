#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <fcntl.h>
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
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    int serveur = socket(AF_INET, SOCK_STREAM, 0);
    if(serveur == -1) {
        std::cerr << "Erreur: " << strerror(errno) << '\n';
        return -1;
    }
    if(bind(serveur, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1) {
        std::cerr << "Erreur:" << strerror(errno) << '\n';
        return -1;
    }
    if(listen(serveur, 5) == -1) {
        std::cerr << "Erreur:" << strerror(errno) << '\n';
        return -1;
    }

    struct sockaddr_in client_addr;
    unsigned client_len = sizeof(client_addr);
    int client = accept(serveur, (struct sockaddr*) &client_addr, &client_len);
    char buffer[1025];
    while(true) {
        bzero(buffer, 1025);
        recv(client, buffer, 1024, 0);
        std::cout << "Requête: " << buffer;

        int index_fd = open("/srv/http/index.php", O_RDONLY);
        bzero(buffer, 1025);
        read(index_fd, buffer, 1024);
        close(index_fd);
        send(client, buffer, sizeof(buffer), MSG_DONTWAIT);
    }

    close(client);
    close(serveur);
    return 0;
}