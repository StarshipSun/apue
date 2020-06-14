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