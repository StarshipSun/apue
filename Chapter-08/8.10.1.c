#include "apue.h"

int main(int argc, char *argv[])
{
    int i;
    char **ptr;
    extern char **environ;
    
    for (i = 0; i < argc; ++i)  // 打印每个命令行参数
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    for (ptr = environ; *ptr != 0; ptr++)  // 打印所有环境变量
    {
        printf("%s\n", *ptr);
    }
    
    exit(0);
}