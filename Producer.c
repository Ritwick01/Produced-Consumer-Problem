#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/un.h>
#include<unistd.h>
#include<time.h>
#include<fcntl.h>
#include<errno.h>

int main() {
    int fd = open("/dev/urandom", O_RDONLY);
    while (1) {
        unsigned char buf[8];
        int file = read(fd, &buf, 8);
        unsigned long long n = 0;
        for (int i = 0; i < 8; i++) {
            n = n << 8;
            n |= buf[i];
        }
        
        int res = syscall(450, n);
        if (res)
            continue;
        printf("Producer has produced: %llu\n", n);
    }

    return 0;
}