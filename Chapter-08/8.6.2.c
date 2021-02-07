#include "apue.h"
#include <sys/wait.h>

/*
 * 如果一个进程 fork 一个子进程，但不要它等待子进程终止，也不希望子进程处于僵死状态直到父进程终止
 * 可以使用两次 fork 来实现
 */
int main(void) 
{
    pid_t pid;
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {  /* first child */
        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid > 0) {  /* first child */
            exit(0);
        }

        /* second child */
        sleep(2);
        printf("second child, parent pid = %ld\n", (long)getppid());
        exit(0);
    }
        
    if (waitpid(pid, NULL, 0) != pid) {  /* wait for first child */
        err_sys("waitpid error");
    }

    exit(0);
}