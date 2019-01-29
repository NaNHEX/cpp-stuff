#include "unistd.h"
#include "sys/wait.h"
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <iostream>


int main() {
    pid_t child_pid;
    do {
        child_pid = fork();
    } while(child_pid == -1 && (errno == EAGAIN));
    if(child_pid == -1) {
        std::cerr << "Fork error: " << strerror(errno) << '\n';
        return EXIT_FAILURE;
    }

    if(child_pid == 0) {
        return EXIT_SUCCESS;
    }
    std::string end;
    std::getline(std::cin, end, '\n');
    return 0;
}