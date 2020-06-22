#include "apue.h"
#include <unistd.h>
#include <fcntl.h>

#define BUFFSIZE 4096

int main(int argc, char *argv[])
{
    if (argc != 3) {
        err_sys("usage: a.out source dest");
    }

    char buf[BUFFSIZE];
    int srcfd, destfd;
    if ((srcfd = open(argv[1], O_RDONLY)) < 0) {
        err_sys("open error for %s", argv[1]);
    }
    if ((destfd = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU)) < 0) {
        err_sys("open error for %s", argv[2]);
    }

    int n;
    while ((n = read(srcfd, buf, BUFFSIZE)) > 0)
    {
        int len = strlen(buf);
        if (len > 0) {
            if (write(destfd, buf, len) != len) {
                err_sys("write error");
            }
        }
        if (n - len > 0) {
            if (lseek(destfd, n - len, SEEK_CUR) < 0) {
                err_sys("seek error");
            }
        }
    }
    if (n < 0) {
        err_sys("read error");
    }
    exit(0);
}