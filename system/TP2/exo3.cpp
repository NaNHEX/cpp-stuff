#include "unistd.h"
#include "sys/wait.h"
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

    pid_t child_pid;
    for (int i = 0; i < 100; ++i) {
        do {
            child_pid = fork();
        } while(child_pid == -1 && (errno == EAGAIN));
        if(child_pid == -1) {
            std::cerr << "Fork error: " << strerror(errno) << '\n';
            return EXIT_FAILURE;
        }

        if(child_pid == 0) {
            srand(time(NULL));
            exit(rand() % 99 + 1);
        }
    }

    int returned = 0;
    for(int i = 0; i < 100; ++i) {
        int wstatus;
        wait(&wstatus);
        if(WIFEXITED(wstatus))
            returned += WEXITSTATUS(wstatus);
    }
    std::cout << (returned / 100);
    return 0;
}