#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include "unistd.h"

extern char** environ;

int main(int argc, char *argv[]) {
    bool isVerbose = false;
    assert(argc <= 3);
    int c;
    while ((c = getopt(argc, argv, "v:")) != -1) {
        switch (c) {
            case 'v': isVerbose = true;
                break;
            case '?': std::cout << "Usage : a.out [-v] [int]";
                return EXIT_FAILURE;
        }
    }
    int num;
    if(isVerbose)
        num = std::stoi(argv[2]);
    else
        num = std::stoi(argv[1]);
    std::cout << "PID: " << getpid() << " ; " << num << '\n';


    if(num > 1) {
        char buffer[11];
        snprintf(buffer, 11, "%d", num - 1);
        if(isVerbose) {
            char * argument[4];
            argument[0] = argv[0];
            argument[1] = argv[1];
            argument[2] = buffer;
            argument[3] = NULL;
            std::cout << "Recouvrement...\n";
            execve("./a.out", argument, environ);
        }
        else {
            char * argument[3];
            argument[0] = argv[0];
            argument[1] = buffer;
            argument[2] = NULL;
            execve("./a.out", argument, environ);
        }
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}