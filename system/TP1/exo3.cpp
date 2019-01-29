#include <unistd.h>
#include <fcntl.h>
#include <cassert>


int main(int argc, char* argv[]) {
    assert(argc == 2);

    assert(link(argv[1], argv[2]) != -1);
    return 0;
}