#include "apue.h"

static void charatatime(char *);

int main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        charatatime("output from child: 1111111111111111111111111111\n");
    } else {
        charatatime("output from parent: 222222222222222222222222222\n");
    }
    exit(0);
}

static void charatatime(char *str)
{
    char *ptr;

    setbuf(stdout, NULL);  // 将标准输出设置为不带缓冲
    for (ptr = str; *ptr != 0; ptr++) {
        putc(*ptr, stdout);  // 每次调用 putc 都会发生系统调用 write，增加竞争
    }
}