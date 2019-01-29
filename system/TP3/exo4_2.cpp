#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <csignal>
#include <cassert>
#include <iostream>

char filename[21];


void readInt(int fd) {
    char read_int[12] = "";
    read(fd, read_int, sizeof(read_int));
    std::cout << read_int << '\n';
}

void manager(int signal) {
    int fd = open(filename, O_RDONLY);
    assert(fd != -1);
    readInt(fd);
    close(fd);
}

int main(int argc, char* argv[]) {
    strncpy(filename, "fichier.txt", 21);
    for(int i = 1; i < argc; ++i) {
        if(strcmp("-f", argv[i]) == 0) {
            if(i + 1 == argc) return -1;
            strncpy(filename, argv[++i], 21);
        }
    }

    std::cout << "PID: " << getpid() << '\n';

    sigset_t set;
    sigfillset(&set);
    sigdelset(&set, SIGUSR1);
    sigprocmask(SIG_SETMASK, &set, nullptr);

    for(int i = 1; i < NSIG; ++i) {
        if(signal(i, manager) == SIG_ERR) {
            std::cerr << "Signal " << i << " (" << strsignal(i) << ") non capturé\n";
        }
    }
    while(true) {
        pause();
    }
    return 0;
}