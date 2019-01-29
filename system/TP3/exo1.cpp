#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <csignal>
#include <cstring>


void manager(int signal) {
    std::cout << "signal reçu par " << getpid()
                 << " numero " << signal
                 << " (" << strsignal(signal) << ")\n";
}

int main() {
    for(int i = 1; i < NSIG; ++i) {
        std::cout << strsignal(i) << "\n";
    }
    std::cout << "PID:" << getpid() << '\n';
    for(int i = 1; i < NSIG; ++i) {
        if(signal(i, manager) == SIG_ERR) {
            std::cerr << "Signal " << i << " (" << strsignal(i) << ") non capturé\n";
        }
    }
    while(true) {
        std::cout << "chut, je taffe...\n";
        pause();
    }
    return 0;
}