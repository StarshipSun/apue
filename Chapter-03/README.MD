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