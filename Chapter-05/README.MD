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
磁盘文件默认是全缓冲的，缓冲区为 4096 字节。

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

### 5.13.1.c
```
lin% gcc -o 5.13.1.out 5.13.1.c -lapue
lin% ./5.13.1.out 
trying to create first temp file...
temp name = /tmp/dirMFAS3f
file exist
trying to create second temp file...
zsh: segmentation fault (core dumped)  ./5.13.1.out
```
mkstemp 函数会修改 template 字符串的占位符。第一个模板使用了数组，字符串空间是在栈上分配的。第二种情况使用的是指针，只有指针自身驻留在栈上，编译器把字符串存放在可执行文件的只读段，mkstemp 函数试图修改字符串时，出现了段错误（segment fault）。

### 5.14.c
```
lin% gcc -o 5.14.out 5.14.c -lapue
lin% ./5.14.out 
initial buffer contents: 
before flush: 
after flush: hello, world
len of string in buf = 12
after fseek: bbbbbbbbbbbbhello, world
len of string in buf = 24
after fclose: hello, worldcccccccccccccccccccccccccccccccccc
len of string in buf = 46
```
调用 fflush 或者 fseek 后会主动追加写入 NULL 字节

## 习题

### [P5.1](./p5.1.c) 用 setvbuf 实现 setbuf
```
lin% gcc -o p5.1.out p5.1.c -lapue
lin% ./p5.1.out
stream = stdin, fully buffered, buffer size = 8192
stream = stdin, unbuffered, buffer size = 1
my_setbuf success: stdin
stream = stdout, fully buffered, buffer size = 8192
stream = stdout, unbuffered, buffer size = 1
my_setbuf success: stdout
stream = stderr, fully buffered, buffer size = 8192
stream = stderr, unbuffered, buffer size = 1
my_setbuf success: stderr
stream = /etc/passwd, fully buffered, buffer size = 8192
stream = /etc/passwd, unbuffered, buffer size = 1
my_setbuf success: /etc/passwd
```
setbuf(stream, buf) 等价于 setvbuf(stream, buf, buf ? _IOFBF : _IONBF, BUFSIZ)
<br>
如果 buf 不为 NULL，buf 应当指向一个长度至少为 BUFSIZ 字节的缓冲，setbuf 将流设置为全缓冲。
<br>
如果 buf 为 NULL，setbuf 将流设置为不带缓冲

### P5.2 图 [5-5](./5.8.1.c) 中的程序利用每次一行 I/O （fgets 和 fputs 函数）复制文件。若将程序中的 MAXLINE 改为 4 ，当复制的行超过该最大值时会出现什么情况？请对此进行解释
```
lin% gcc -o p5.2.out p5.2.c -lapue
lin% ./p5.2.out 
fu2222adyh324hsdfsds
fu2222adyh324hsdfsds
```
这两个函数仍然能够工作。
<br>
fgets 函数读入数据，直到行结束或者缓冲区满，最后留一个字节存放终止 NULL 字节。
<br>
fputs 只负责将缓冲区的内容输出直到遇到一个 NULL 字节

### P5.3 printf 返回 0 值表示什么？
表示printf没有输出任何字符

### P5.4 下面的代码在一些机器上运行正确，而在另外一些机器运行时出错，解释原因所在
```
#include <stdio.h>

int main(void)
{
    char c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}
```
getchar 函数返回的是 int 类型，而不是 char 类型。EOF 经常被定义为 -1，如果系统使用的是无符号字符类型，那么返回的 EOF 被保存到字符 c 后将不再是 -1, 所以程序会进入死循环。

### P5.5 对标准 I/O 流如何使用 fsync 函数（见 3.13 节）？
先调用 fflush 后调用 fileno 获取标准 I/O 对应的文件描述符作为 fsync 的入参。
<br>
如果不调用 fflush，所有数据仍然在内存缓冲区中，此时调用 fsync 将没有任何效果。

### P5.6 在图 1-7 和图 1-10 程序中，打印的提示信息没有包含换行符，程序也没有调用 fflush 函数，请解释输出提示信息的原因是什么。
当程序交互运行时，标准输入和标准输出均为行缓冲方式。每次调用fgets时标准输出设备将自动冲洗。

### P5.7 基于 BSD 的系统提供了 funopen 的函数调用使我们可以拦截读、写、定位以及关闭一个流的调用。使用这个函数为 FreeBSD 和 MacOS X 实现 fmemopen。
运行环境是 Linux，没有 funopen 函数调用
