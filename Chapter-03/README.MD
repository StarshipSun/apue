# 第三章 文件I/O

## 随书代码

### 3.6.c
```
# 如果文件描述符指向的是一个管道、FIFO或网络套接字，则lseek返回-1
lin% gcc -o 3.6.out 3.6.c -lapue
lin% ./3.6.out 
cannot seek
lin% ./3.6.out < /etc/passwd
seek OK
lin% cat < /etc/passwd | ./3.6.out 
cannot seek
```

### 3.6.1.c
```
lin% gcc -o 3.6.1.out 3.6.1.c -lapue 
lin% ./3.6.1.out                    
lin% ls -ls file.hole 
8 -rw-r--r-- 1 lin lin 16394 Jun 14 15:50 file.hole
lin% od -c file.hole 
0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
*
0040000   A   B   C   D   E   F   G   H   I   J
0040012
```

### 3.9.c
```
lin% gcc -o 3.9.out 3.9.c -lapue 
lin% ./3.9.out < file.hole > file
```

### 3.14.1.c
```
lin% gcc -o 3.14.1.out 3.14.1.c -lapue
lin% ./3.14.1.out 0
read write
lin% ./3.14.1.out 1
read write
lin% ./3.14.1.out 0 < /dev/tty
read only
lin% ./3.14.1.out 1 > temp.foo 
lin% cat temp.foo
write only
lin% ./3.14.1.out 2 2>>temp.foo
write only, append
lin% ./3.14.1.out 5 5<>temp.foo
read write
```

## 习题

### P3.1 当读/写磁盘文件时，本章中描述的函数确实是不带缓冲机制的吗？请说明原因
使用系统调用读/写磁盘在用户空间是不带缓冲机制的，但是内核在提供读写调用的时候是带缓冲机制的。

### [P3.2](./p3.2.c) 编写一个与3.12节中dup2功能相同的函数，要求不调用fcntl函数，并且要有正确的出错处理
```
lin% gcc -o p3.2.out p3.2.c -lapue
lin% ./p3.2.out                   
fd2:10 no open
dup2 for stdin_fileno: 0, newfd: 10
```

### P3.4 许多程序中都包含下面一段代码：
```
dup2(fd, 0);
dup2(fd, 1);
dup2(fd, 2);
if (fd > 2) close(fd);
```
为了说明if语句的必要性，假设fd是1,画出每次调用dup2时3个描述符项及相应的文件表项的变化情况。然后再画出fd为3的情况

答： 当fd为1时，dup(fd, 1)没有复制文件描述符fd而是直接返回1,此时文件描述符有3个（0、1、2）。当fd为3时，此时文件描述符有4个（0、1、2、3），所以调用了close将fd关闭

### P3.5 在Bourne shell、Bourne-again shell和Korn shell中，digit1>&digit2表示要将描述符digit1重定向至描述符digit2的同一文件。请说明下面两条命令的区别。
```
./a.out > outfile 2>&1
./a.out 2>&1 > outfile
```
./a.out > outfile 2>&1：将标准输出、标准错误都重定向到outfile文件
./a.out 2>&1 > outfile：将标准输出重定向到outfile文件、标准错误重定向到终端

### [P3.6](./p3.6.c) 如果使用追加标志打开一个文件以便读、写，能否仍用lseek在任一位置开始读？能否用lseek更新文件中任一部分的数据？请编写一段程序验证。
```
lin% gcc -o p3.6.out p3.6.c -lapue
lin% ./p3.6.out 
lseek offset 3, return 3
lseek offset 3, return 3
lseek read
dfeg1234567
```
可以使用lseek和read在任一位置开始读。
可以使用lseek调整文件偏移量，但是使用write函数写数据之前会自动将文件偏移量设置为文件尾，所以写文件只能从文件尾开始。
