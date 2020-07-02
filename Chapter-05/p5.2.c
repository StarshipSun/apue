#include "apue.h"

int main(void)
{
    char buf[4];

    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (fputs(buf, stdout) == EOF) {
            err_sys("fputs error");
        }
    }

    if (ferror(stdin)) {
        err_sys("input error");
    }
    exit(0);
}