#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <cassert>
#include <cstdlib>

constexpr char hexmap[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                           '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

int readNBytes(int descIn, size_t n, char* res) {
    return read(descIn, res, n);
}

//16 nombres de 2 chiffres par ligne séparés par un espace
void hexDump(const char* reference) {
    std::string s(12, ' ');
    for (int i(0); i < 6; ++i) {
        s[2 * i]     = hexmap[(reference[i] & 0xF0) >> 4];
        s[2 * i + 1] = hexmap[reference[i] & 0x0F];
    }

    for(size_t i(0); i < s.length(); ++i) {
        if(i % 2 == 0)
            std::cout << ' ';
        std::cout << s[i];
    }
    std::cout << '\n';
}

int main(int argc, char* argv[]) {
    char* endptr;
    assert(argc == 4);

    int fd = open(argv[1], O_RDONLY);
    assert(fd != -1);

    assert(lseek(fd, atoi(argv[2]), SEEK_CUR) != -1);

    char* buf = static_cast<char *>(malloc(strtoul(argv[3], &endptr, 10) + 1));
    buf[readNBytes(fd, strtoul(argv[3], &endptr, 10), buf)] = '\0';
    hexDump(buf);
    free(buf);
    return 0;
}