#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
    int fd = open("text.bin", O_CREAT|O_WRONLY|O_TRUNC, 0644);
    if(fd >= 0) {
        int valeur = 0x42;
        write(fd, &valeur, sizeof(valeur));
    }

    return 0;
}