#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <csignal>
#include <cassert>
#include <iostream>

unsigned long cpt = 0;

void manager(int signal) {
    if(signal == SIGUSR1) {
        std::cout << cpt << '\n';
    }
    else if(signal == SIGUSR2) {
        exit(cpt);
    }
}

int main() {
    std::cout << "PID: " << getpid() << '\n';

    sigset_t set;
    sigfillset(&set);
    sigdelset(&set, SIGUSR1);
    sigdelset(&set, SIGUSR2);
    sigprocmask(SIG_SETMASK, &set, nullptr);

    for(int i = 1; i < NSIG; ++i) {
        if(signal(i, manager) == SIG_ERR) {
            std::cerr << "Signal " << i << " (" << strsignal(i) << ") non capturé\n";
        }
    }
    while(true) {
        ++cpt;
    }
}