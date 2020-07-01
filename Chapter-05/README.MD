# 第五章 标准I/O库

## 随书代码

### 5.8.c
```
lin% gcc -o 5.8.out 5.8.c -lapue
lin% ./5.8.out 
23sfgrdhy
23sfgrdhy
```

### 5.8.1.c
```
lin% gcc -o 5.8.1.out 5.8.1.c -lapue
lin% ./5.8.1.out 
34saff
34saff
bbbbbdddddd
bbbbbdddddd
```

### 5.12.c
```
lin% gcc -o 5.12.out 5.12.c -lapue
lin% ./5.12.out                   
enter any character
1
one line to standard error
stream = stdin, fully buffered, buffer size = 1024
stream = stdout, fully buffered, buffer size = 1024
stream = stderr, unbuffered, buffer size = 1
stream = /etc/passwd, fully buffered, buffer size = 4096

lin% ./5.12.out < /etc/group > std.out 2> std.err 
lin% cat std.err 
one line to standard error
lin% cat std.out 
enter any character
stream = stdin, fully buffered, buffer size = 4096
stream = stdout, fully buffered, buffer size = 4096
stream = stderr, unbuffered, buffer size = 1
stream = /etc/passwd, fully buffered, buffer size = 4096
```
可见标准输入、输出连至终端时，他们是行缓冲的，缓冲区为1024字节。
<br>
标准错误是不带缓冲的，以便错误信息能够及时显示。
<br>
磁盘文件默认是全缓冲的，缓冲区为4096字节。

### 5.13.c
```
lin% gcc -o 5.13.out 5.13.c -lapue
/usr/bin/ld: /tmp/ccyY5cXu.o: in function `main':
5.13.c:(.text+0x20): 警告：the use of `tmpnam' is dangerous, better use `mkstemp'
lin% ./5.13.out 
/tmp/filef2N6BO
/tmp/fileb6lkCR
one line of output
```