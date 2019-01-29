#include "unistd.h"
#include "sys/wait.h"
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <iostream>


int main(int argc, char* argv[]) {
    int nb_child = 4;
    for(int i = 1; i < argc; ++i) {
        if(!strcmp("-n", argv[i])) {
            if(i + 1 == argc) return -1;
            nb_child = atoi(argv[++i]);
        }
    }

    int sleep_time = 5;
    for(int i = 1; i < argc; ++i) {
    if(!strcmp("-s", argv[i])) {
        if(i + 1 == argc) return -1;
            sleep_time = atoi(argv[++i]);
        }
    }

    std::cout << "Bienvenue à la foire du slip!";

    for (int i = 0; i < nb_child; ++i) {
        pid_t child_pid;
        do {
            child_pid = fork();
        } while(child_pid == -1 && (errno == EAGAIN));
        if(child_pid == -1) {
            std::cerr << "Fork error: " << strerror(errno) << '\n';
            return EXIT_FAILURE;
        }

        if(child_pid == 0) {
            std::cout << getpid() << " commence!";
            sleep(sleep_time);
            std::cout << getpid() << " adieu!\n";
            return EXIT_SUCCESS;
        }

    }
    return 0;
}