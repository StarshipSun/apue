#include "apue.h"
#include <sys/wait.h>

// 使用宏打印进程终止状态的说明
void pr_exit(int status)
{
    if (WIFEXITED(status))
        printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
        printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
               WCOREDUMP(status) ? " (core file generated)" : "");
#else
               "");
#endif
    else if (WIFSTOPPED(status))
        printf("child stopped, signal number = %d\n", WSTOPSIG(status));
}

int main(void)
{
    pid_t pid;
    int status;

    if ((pid = fork()) < 0) 
        err_sys("fork error");
    else if (pid == 0)  /* child */
        exit(7);  // 正常退出

    if (wait(&status) != pid)  /* wait for child */
        err_sys("wait error");
    pr_exit(status);  /* print its status */

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)  /* child */
        abort();  // 信号中断，发出 SIGABRT 信号

    if (wait(&status) != pid)  /* wait for child */
        err_sys("wait error");
    pr_exit(status);  /* print its status */

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)  /* child */
        status /= 0;  // 除以零，发出 SIGFPE 信号

    if (wait(&status) != pid)  /* wait for child */
        err_sys("wait error");
    pr_exit(status);  /* print its status */
    exit(0);
}