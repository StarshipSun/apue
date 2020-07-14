# 第八章 进程控制

## 随书代码

### 8.3.c
```
lin% gcc -o 8.3.out 8.3.c -lapue

lin% ./8.3.out 
a write to stdout
before fork
pid = 1617, glob = 7, var = 89
pid = 1616, glob = 6, var = 88

lin% ./8.3.out > temp.out
lin% cat temp.out 
a write to stdout
before fork
pid = 3931, glob = 7, var = 89
before fork
pid = 3930, glob = 6, var = 88
```
* 父进程和子进程的变量不共享
* write 函数不带缓冲，所以调用 write 会马上输出
* 标准 I/O 是带缓冲的，如果是连到终端设备是行缓冲，如果是文件则是全缓冲。
* 当重定向标准输出到文件时，fork 之前调用了一次 printf，但是调用 fork 之后在数据仍然在缓冲区中，然后在将父进程数据空间复制到子进程中时，缓冲区数据也被复制到子进程中，调用 exit 之 flush 标准 I/O 导致数据出现两次。