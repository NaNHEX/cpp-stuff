#include <cassert>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>


int main(int argc, char *argv[]) {
    assert(argc == 2);

    struct stat buf;

    assert(stat(argv[1], &buf) != -1);
    std::cout << "type : ";
    switch (buf.st_mode & S_IFMT)
    {
    case S_IFBLK:
        std::cout << "block device\n";
        break;
    case S_IFCHR:
        std::cout << "character device\n";
        break;
    case S_IFDIR:
        std::cout << "directory\n";
        break;
    case S_IFIFO:
        std::cout << "FIFO/pipe\n";
        break;
    case S_IFLNK:
        std::cout << "symlink\n";
        break;
    case S_IFREG:
        std::cout << "regular file\n";
        break;
    case S_IFSOCK:
        std::cout << "socket\n";
        break;
    default:
        return -1;
    }

    std::cout << std::oct << "mode : " << buf.st_mode << '\n';
    std::cout << std::dec << "User ID : " << buf.st_uid << '\n';
    std::cout << "Group ID : " << buf.st_gid << '\n';
    std::cout << "Inode n°" << buf.st_ino << '\n';

    return 0;
}