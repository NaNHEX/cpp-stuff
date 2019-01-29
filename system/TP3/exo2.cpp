#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <csignal>
#include <iostream>


void manager(int sig) {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = manager;
    sa.sa_flags = SA_RESETHAND | SA_NODEFER;
    sigaction(sig, &sa, nullptr);
    std::cout << "debut gestion\n";
    for(int i = 1; i <= 4; ++i) {
        std::cout << i << '\n';
        sleep(1);
    }
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = manager;
    sa.sa_flags = SA_RESETHAND | SA_NODEFER;
    sigaction(SIGUSR1, &sa, nullptr);
    if(fork() == 0) {
        kill(getppid(), SIGUSR1);
        sleep(1);
        kill(getppid(), SIGUSR1);
    }
    else while(true){ pause(); }
    return 0;
}