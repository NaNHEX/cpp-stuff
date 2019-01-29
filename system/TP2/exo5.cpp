#include <iostream>
#include "unistd.h"
#include "sys/wait.h"
#include <cerrno>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main() {
    const int fdWR = open("tutu", O_WRONLY | O_CREAT | O_EXCL, 0644);
    const int fdRD = open("tutu", O_RDONLY, 0644);
    if(fdWR == -1 || fdRD == -1) {
        std::cerr << "Open error: " << strerror(errno) << '\n';
        return EXIT_FAILURE;
    }

    pid_t child_pid;
    do {
        child_pid = fork();
    } while(child_pid == -1 && (errno == EAGAIN));
    if(child_pid == -1) {
        std::cerr << "Fork error: " << strerror(errno) << '\n';
        return EXIT_FAILURE;
    }
    else if(child_pid != 0) {
        int n;
        std::cout << "Entrez votre nombre : ";
        std::cin >> n;
        write(fdWR, &n, sizeof(int));
        close(fdWR);

        int wstatus;
        wait(&wstatus);
        if(WIFEXITED(wstatus)) {
            if (WEXITSTATUS(wstatus) == EXIT_SUCCESS) {
                unlink("tutu");
                return EXIT_SUCCESS;
            }
        }
    }
    else if(child_pid == 0) {
        int n;
        unsigned long bytesRead = 0;
        do {
            const int ret = read(fdRD, &n, sizeof(int));
            if(ret == -1) {
                std::cerr << "Read error: " << strerror(errno) << '\n';
                return EXIT_FAILURE;
            }
            bytesRead += ret;
        } while(bytesRead < sizeof(int));
        std::cout << "Fils, chiffre lu : " << n << '\n';
        close(fdRD);
        exit(EXIT_SUCCESS);
    }

    return EXIT_FAILURE;
}