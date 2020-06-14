#include "apue.h"
#include <fcntl.h>

int main(void) {
    char *filename = "p3.6.file";
    char buf1[] = "abcdfeg";
    char buf2[] = "1234567";

    // 以追加标志打开文件
    int fd;
    if ((fd = open(filename, O_CREAT | O_RDWR | O_APPEND)) < 0) {
        err_sys("open error");
    }

    // 追加写
    int n;
    if ((n = write(fd, buf1, strlen(buf1))) != n) {
        err_sys("append write error");
    }

    // lseek之后写
    int offset;
    if ((offset = lseek(fd, 3, SEEK_SET)) == -1) {
        err_sys("lseek error");
    }
    printf("lseek offset 3, return %d\n", offset);

    if ((n = write(fd, buf2, strlen(buf2))) != n) {
        err_sys("lseek write error");
    }

    // lseek之后读
    if ((offset = lseek(fd, 3, SEEK_SET)) == -1) {
        err_sys("lseek error");
    }
    printf("lseek offset 3, return %d\n", offset);

    printf("lseek read\n");
    int MAXSIZE = 4096;
    char buf[MAXSIZE];
    while ((n = read(fd, buf, MAXSIZE)) > 0) {
        printf("%s", buf);
    }

    printf("\n");
}