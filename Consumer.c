#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/un.h>
#include<unistd.h>
#include<time.h>
#include<fcntl.h>
#include<errno.h>

int main() {
    while (1) {
        unsigned long long n = 0;
        int res = syscall(449, &n);
        printf("Consumer has consumed: %llu\n", n);
    }

    return 0;
}