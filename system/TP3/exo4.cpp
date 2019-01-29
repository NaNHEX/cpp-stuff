#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <cassert>
#include <csignal>
#include <iostream>


int main(int argc, char* argv[]) {
    char filename[21];
    strncpy(filename, "fichier.txt", 21);
    pid_t pid = -1;
    for(int i = 1; i < argc; ++i) {
        if(strcmp("-f", argv[i]) == 0) {
            if(i + 1 == argc) return -1;
            strncpy(filename, argv[++i], 21);
        }
        if(strcmp("-p", argv[i]) == 0) {
            if(i + 1 == argc) return -1;
            pid = atoi(argv[++i]);
        }
    }
    assert(pid != -1);

    char input[12] = "";
    std::cin >> input;

    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    assert(fd != -1);
    write(fd, input, sizeof(input));
    close(fd);

    assert(kill(pid, SIGUSR1) == 0);
    return 0;
}