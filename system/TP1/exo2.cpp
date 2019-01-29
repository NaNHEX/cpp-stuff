#include <cassert>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>

int main() {
    const char directoryPath[] = "./";
    struct stat buf;

    unsigned long precedentInode;
    while(true) {
        assert(stat(directoryPath, &buf) != -1);
        unsigned long currentInode = buf.st_ino;
        if(currentInode == precedentInode) {
            break;
        }

        std::cout << currentInode << '\n';
        assert(chdir("../") != -1);
        precedentInode = currentInode;
    }
    return 0;
}