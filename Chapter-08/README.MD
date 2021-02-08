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

### 8.6.1.c
```
lin% gcc -o 8.6.1.out 8.6.1.c -lapue
lin% ./8.6.1.out                    
normal termination, exit status = 7
abnormal termination, signal number = 6
abnormal termination, signal number = 8
```
* 使用 pid_t wait(int *status) 函数等待子进程终止，只要有一个子进程终止，wait 就返回，否则阻塞。
* 使用宏来判断进程的状态和获得进程的退出/终止信号。

### 8.6.2.c
```
lin% gcc -o 8.6.2.out 8.6.2.c -lapue
lin% ./8.6.2.out                    
lin% second child, parent pid = 1
```
* 如果一个进程 fork 一个子进程，但不要它等待子进程终止，也不希望子进程处于僵死状态直到父进程终止，可以使用两次 fork 来实现

### 8.9.1.c
演示父子进程的竞争条件
```
lin% ./8.9.1.out
output from parent: 2222222222222o2u2t2p2u2t2 2f2r2o2m2 2c2h2i
ld: 1111111111111111111111111111
```

### 8.9.2.c
演示进程间通信
```
lin% gcc -o 8.9.2.out 8.9.2.c -lapue
lin% ./8.9.2.out 
output from parent: 222222222222222222222222222
output from child: 1111111111111111111111111111
```

### 8.10.1.c
exec并不创建新的进程，只是用磁盘上的一个新程序替换了当前进程的正文段、数据段、堆段和栈段