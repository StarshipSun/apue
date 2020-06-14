#include "apue.h"
#include <errno.h>

int my_dup2(int, int);

int main(void) {
    int newfd = my_dup2(STDIN_FILENO, 10);
    printf("dup2 for stdin_fileno: %d, newfd: %d\n", STDIN_FILENO, newfd);
    exit(0);
}

int my_dup2(int fd, int fd2) {
    if (fd == fd2) {
        return fd2;
    }

    if (close(fd2) < 0) {
        if (errno == EBADF) {
            printf("fd2:%d no open\n", fd2);
        } else {
            err_sys("close fd2 error");
        }
    }

    int newfd;
    while ((newfd = dup(fd)) != fd2)
    {
        if (newfd < 0) {
            err_sys("dup error");
        }
    }
    
    return newfd;
}