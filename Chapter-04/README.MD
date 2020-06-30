# 第四章 文件和目录

## 随书代码

### 4.3.c
```
lin% gcc -o 4.3.out 4.3.c -lapue
lin% ./4.3.out /etc/passwd /etc /dev/log /dev/tty /dev/sr0 /dev/cdrom  
/etc/passwd: regular
/etc: directory
/dev/log: symbolic link
/dev/tty: character special
/dev/sr0: block special
/dev/cdrom: symbolic link
```

### 4.7.c
```
lin% gcc -o 4.7.out 4.7.c -lapue

lin% ls -l 4.7.out 
-rwxr-xr-x 1 lin lin 17528 Jun 21 10:22 4.7.out
lin% ./4.7.out 4.7.out 
read access OK
open for reading OK

lin% ls -l /etc/shadow
-rw------- 1 root root 772 Apr 25 15:54 /etc/shadow
lin% ./4.7.out /etc/shadow
access error for /etc/shadow: Permission denied
open error for /etc/shadow: Permission denied
 
lin% su
[root@lin Chapter-04]# chown root 4.7.out   将文件用户ID改为root
[root@lin Chapter-04]# chmod u+s 4.7.out    打开设置用户ID位
[root@lin Chapter-04]# ls -l 4.7.out
-rwsr-xr-x 1 root lin 17528 Jun 21 10:22 4.7.out
[root@lin Chapter-04]# exit
exit

lin% ./4.7.out /etc/shadow
access error for /etc/shadow: Permission denied
open for reading OK
```

### 4.8.c
```
lin% gcc -o 4.8.out 4.8.c -lapue
lin% 
lin% umask
022
lin% ./4.8.out 
lin% ls -l foo bar
-rw------- 1 lin lin 0 Jun 21 10:55 bar
-rw-rw-rw- 1 lin lin 0 Jun 21 10:55 foo
lin% umask
022
```

### 4.9.c
```
lin% ls -l foo bar
-rw------- 1 lin lin 0 Jun 21 10:55 bar
-rw-rw-rw- 1 lin lin 0 Jun 21 10:55 foo
lin% 
lin% gcc -o 4.9.out 4.9.c -lapue
lin% ./4.9.out 
lin% 
lin% ls -l foo bar              
-rw-r--r-- 1 lin lin 0 Jun 21 10:55 bar
-rw-rwSrw- 1 lin lin 0 Jun 21 10:55 foo
```

### 4.15.c
```
lin% gcc -o 4.15.out 4.15.c -lapue    

lin% ls -l tempfile 
-rw-r--r-- 1 lin lin 1024000000 Jun 21 16:45 tempfile
lin% df /home
文件系统           1K-块     已用      可用 已用% 挂载点
/dev/sdb       479670976 34262276 420972988    8% /

lin% ./4.15.out &
[1] 9144
lin% file unlinked

ls -l tempfile
ls: 无法访问 'tempfile': 没有那个文件或目录
lin% df /home      
文件系统           1K-块     已用      可用 已用% 挂载点
/dev/sdb       479670976 34262276 420972988    8% /
lin% done

[1]  + done       ./4.15.out

lin% df /home      
文件系统           1K-块     已用      可用 已用% 挂载点
/dev/sdb       479670976 33262272 421972992    8% /
```

### 4.17
```
lin% ln -s /no/such/file myfile
lin% ls myfile
myfile
lin% cat myfile
cat: myfile: 没有那个文件或目录
lin% ls -l myfile
lrwxrwxrwx 1 lin lin 13 Jun 21 17:23 myfile -> /no/such/file
```

### 4.20.c
```
lin% gcc -o 4.20.out 4.20.c -lapue 
lin% ls -l changemod times
-rw-rw-r--. 1 lin lin 0 6月  20 04:45 changemod
-rw-rw-r--. 1 lin lin 0 6月  20 04:45 times 
lin% ls -lu changemod times 
-rw-rw-r--. 1 lin lin 0 6月  20 04:45 changemod
-rw-rw-r--. 1 lin lin 0 6月  20 04:45 times
lin% ls -lc changemod times
-rw-rw-r--. 1 lin lin 0 6月  20 04:45 changemod
-rw-rw-r--. 1 lin lin 0 6月  20 04:45 times
lin% 
lin% date
2020年 06月 20日 星期六 04:48:19 CST
lin% 
lin% ./4.20.out changemod times 
lin% 
lin% ls -l changemod times 
-rw-rw-r--. 1 lin lin 0 6月  20 04:48 changemod
-rw-rw-r--. 1 lin lin 0 6月  20 04:45 times
lin% ls -lu changemod times
-rw-rw-r--. 1 lin lin 0 6月  20 04:45 changemod
-rw-rw-r--. 1 lin lin 0 6月  20 04:45 times
lin% ls -lc changemod times
-rw-rw-r--. 1 lin lin 0 6月  20 04:48 changemod
-rw-rw-r--. 1 lin lin 0 6月  20 04:48 times
```

### 4.22.c
```
lin% gcc -o 4.22.out 4.22.c -lapue
lin% ./4.22.out /home/lin/Desktop/apue 
regular files  =     254, 63.66 %
directories    =     144, 36.09 %
block special  =       0,  0.00 %
char special   =       0,  0.00 %
FIFOs          =       0,  0.00 %
symbolic links =       1,  0.25 %
sockets        =       0,  0.00 %
```

### 4.23.c
```
lin% gcc -o 4.23.out 4.23.c -lapue
lin% pwd
/home/lin/Desktop/apue/Chapter-04
lin% ./4.23.out 
chdir to /tmp succeeded
lin% pwd
/home/lin/Desktop/apue/Chapter-04
```

### 4.23.1.c
```
lin% sudo ln -s /var/spool /usr/spool
lin% gcc -o 4.23.1.out 4.23.1.c -lapue
lin% ./4.23.1.out 
cwd = /var/spool/mail
lin% ls -l /usr/spool 
lrwxrwxrwx 1 root root 10 Jun 22 19:58 /usr/spool -> /var/spool
```

### 4.24.c
```
lin% gcc -o 4.24.out 4.24.c -lapue

lin% ./4.24.out / /home/lin /dev/tty[01]
/: dev = 8/16
/home/lin: dev = 8/16
/dev/tty0: dev = 0/5 (character) rdev = 4/0
/dev/tty1: dev = 0/5 (character) rdev = 4/1

lin% mount
...
/dev/sdb on / type ext4 (rw,relatime)
...

lin% ls -l /dev/tty[01] /dev/sdb 
brw-rw---- 1 root disk 8, 16 Jun 22 19:35 /dev/sdb
crw--w---- 1 root tty  4,  0 Jun 22 19:35 /dev/tty0
crw--w---- 1 root tty  4,  1 Jun 22 19:35 /dev/tty1
```

## 习题

### [P4.1](./p4.1.c) 用stat函数替换[4.3.c](./4.3.c)程序中的lstat函数，如若命令行参数之一是符号链接，会发生什么变化？
```
lin% ./4.3.out /usr/spool 
/usr/spool: symbolic link
lin% 
lin% gcc -o p4.1.out p4.1.c -lapue
lin% ./p4.1.out /usr/spool 
/usr/spool: directory
```
使用stat会跟随符号链接，得到的文件状态是符号链接指向文件的状态

### P4.2 如果文件模式创建屏蔽字是777（八进制），结果会怎样？用shell的umask命令验证该结果。
```
lin% umask 777
lin% umask 
0777
lin% touch temp
lin% ls -l temp 
---------- 1 lin lin 0 Jun 22 20:47 temp
lin% 
lin% cat temp 
cat: temp: 权限不够
```

### P4.3 关闭一个你所拥有文件的用户读权限，将导致拒绝你访问自己的文件，对此进行验证。
```
lin% echo "abcd" >> temp
lin% ls -l temp 
-rw-r--r-- 1 lin lin 5 Jun 22 20:49 temp
lin% cat temp 
abcd
lin% 
lin% chmod u-r temp 
lin% ls -l temp
--w-r--r-- 1 lin lin 5 Jun 22 20:49 temp
lin%    
lin% cat temp 
cat: temp: 权限不够
```

### P4.4 创建文件foo和bar后，运行[4.8.c](./4.8.c)的程序，将发生什么情况？
```
lin% ls -l bar foo 
-rw-r--r-- 1 lin lin 4 Jun 22 22:24 bar
-rw-rwSrw- 1 lin lin 4 Jun 22 22:24 foo
lin% 
lin% ./4.8.out 
lin% 
lin% ls -l bar foo
-rw-r--r-- 1 lin lin 0 Jun 22 22:24 bar
-rw-rwSrw- 1 lin lin 0 Jun 22 22:24 foo
```
权限位没变，但是文件被截断

### P4.5 4.12节中讲到一个普通文件的大小可以为0，同时我们又知道st_size字段是为目录或符号链接定义的，那么目录和符号链接的长度是否可以为0？
目录的长度不能为0,因为它总是包含.和..目录
符号链接的长度指的是其路径名包含的字符数，至少有一个字符，所以长度也不能为0

### [P4.6](./p4.6.c) 编写一个类似cp(1)的程序，它复制包含空洞的文件，但不将字节0写到输出文件中去。
```
lin% ls -ls file.hole 
8 -rw-r--r-- 1 lin lin 16394 Jun 22 23:04 file.hole
lin% od -c file.hole 
0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
*
0040000   A   B   C   D   E   F   G   H   I   J
0040012
lin% 
lin% gcc -o p4.6.out p4.6.c -lapue    
lin% ./p4.6.out file.hole file.hole.cp
lin%                                  
lin% ls -ls file.hole file.hole.cp 
8 -rw-r--r-- 1 lin lin 16394 Jun 22 23:04 file.hole
8 -rwx------ 1 lin lin 16394 Jun 22 23:05 file.hole.cp
lin% od -c file.hole
0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
*
0040000   A   B   C   D   E   F   G   H   I   J
0040012
lin% od -c file.hole.cp 
0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
*
0040000   A   B   C   D   E   F   G   H   I   J
0040012
```

### P4.7 在4.12节ls命令的输出中，core和core.copy的访问权限不同，如果创建两个文件时umask没有变，说明为什么会出现这种差别。
1、更改进程的文件模式创建屏蔽字并不影响其父进程的屏蔽字。
2、core文件的创建是3.6节中程序调用系统调用时创建的，传入的文件访问权限是FILE_MODE，
即rw-r--r--。使用shell的cat命令对新文件也有一个默认的访问权限，为rw-rw-rw-,它会收到当前umask的影响。
```
#include "apue.h"
#define	FILE_MODE	(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
```

```
lin% touch temp

lin% umask
022
lin% cat temp > temp.cpy
lin% ls -l temp.cpy
-rw-r--r-- 1 lin lin 0 Jun 23 20:12 temp.cpy

lin% umask 0
lin% umask 
000
lin% cat temp > temp.cpy2
lin% ls -l temp.cpy2
-rw-rw-rw- 1 lin lin 0 Jun 23 20:15 temp.cpy2
```

### P4.8 在运行[4.15.c](./4.15.c)的程序时，使用了df(1)命令来检查空闲的磁盘空间。为什么不使用du(1)命令？
du命令需要文件名，如 du tempfile。
只有当unlink函数返回时才释放tempfile的目录项，du . 命令没有计算仍然被tempfile占用的空间。所以只能使用df命令查看文件系统中实际可用的空闲空间。

### P4.9 图4-20中显示unlink函数会修改文件状态更改时间，这是怎样发生的？
unlink将文件的i节点的硬连接数减1

### P4.10 4.22节中，系统对可打开文件数的限制对myftw函数会产生什么影响？
可打开的文件数影响遍历文件系统的深度

### [P4.11](./p4.11.c) 在4.22节中的myftw从不改变其目录，对这种处理方法进行改动：每次遇到一个目录就用其调用chdir，这样每次调用lstat时就可以使用文件名而非路径名，处理完所有的目录项后执行chdir("..")。比较这种版本的程序和书中程序的运行时间。
```
lin% gcc -o p4.11.out p4.11.c -lapue 

lin% time ./p4.11.out /home/lin                  
regular files  =   24447, 86.81 %
directories    =    3498, 12.42 %
block special  =       0,  0.00 %
char special   =       0,  0.00 %
FIFOs          =       0,  0.00 %
symbolic links =     215,  0.76 %
sockets        =       0,  0.00 %
./p4.11.out /home/lin  0.03s user 0.05s system 99% cpu 0.079 total
lin% 
lin% time ./4.22.out /home/lin 
regular files  =   24447, 86.81 %
directories    =    3498, 12.42 %
block special  =       0,  0.00 %
char special   =       0,  0.00 %
FIFOs          =       0,  0.00 %
symbolic links =     215,  0.76 %
sockets        =       0,  0.00 %
./4.22.out /home/lin  0.02s user 0.07s system 99% cpu 0.084 total
```

### P4.12 每个进程都有一个根目录用于解析绝对路径名，可以通过chroot函数改变根目录。在手册中查阅此函数。说明这个函数什么时候有用。
1、用于辅助安全性。利用chroot将目录当作新的根目录，就可以阻止用户访问此目录以外的文件。（FTP程序）
2、用于在另一台机器上构造一个文件系统层次结构的副本，修改此副本，不会更改原来的文件系统，可用于测试新软件包的安装。
chroot只能由超级用户执行，一旦更改了一个进程的根，该进程及其后代进程就再也不能恢复至原先的根。

### P4.13 如何只设置两个时间值中的一个来使用utimes函数？
先调用stat函数取得文件的3个时间值，然后调用utimes设置期望值。在调用utimes时我们不希望改变的值应当是stat中相应的值。

### P4.14 有些版本的finger(1)命令输出“New mail received ...” 和 “unread since ...”，其中...表示相应的日期和时间。程序是如何决定这些日期和时间的？
finger(1)对邮箱调用stat函数，最近一次的修改时间是上一次接收邮件的时间，最近访问时间是上一次读邮件的时间。

### P4.15 用cpio(1)和tar(1)命令检查档案文件的格式（请参阅《UNIX程序员手册》第5部分中的说明）。3个可能的时间值中哪几个是为每一个文件保存的？你认为文件复原时，文件的访问时间是什么？为什么？
cpio和tar归档的时候保存的是文件的修改时间（st_mtim），抽取时复原修改时间，将访问时间设置为抽取文件时的时间。
<br>
cpio 参数 -a 可以重新设置文件的访问时间，参数 -m 将文件的修改时间和访问时间设置为归档时间。
<br>
tar 参数 -m 将文件的修改时间设置为抽取文件时的时间

### [P4.16](./p4.16.c) UNIX系统对目录树的深度有限制吗？编写一个程序循环，在每次循环中，创建目录，并将该目录更改为工作目录。确保叶节点的绝对路径名的长度大于系统的PATH_MAX限制。可以调用getcwd得到目录的路径名吗？标准UNIX系统工具是如何处理长路径名的？对目录可以使用tar或cpio命令归档吗？
```
lin% gcc -o p4.16.out  p4.16.c -lapue
lin% ./p4.16.out
PATH_MAX: 4096
  0 getcwd success
  1 getcwd success
......
......
......
 73 getcwd success
 74 getcwd success
 75 getcwd error: Numerical result out of range
 76 getcwd error: Numerical result out of range
......
......
......
998 getcwd error: Numerical result out of range
999 getcwd error: Numerical result out of range
```
当叶节点的绝对路径名的长度大于系统的PATH_MAX限制时，调用getcwd会失败，但是目录的深度没有限制，依然可以调用chdir。

```
tar -cf test.tar alonglonglonglonglonglonglonglonglonglonglonglongname
```
对目录可以使用tar命令归档

### P4.17 3.16节中描述了/dev/fd特征。如果每个用户都可以访问这些文件，则其访问权限必须为 rw-rw-rw- 。有些程序创建输出文件时，先删除该文件以确保该文件名不存在，忽略返回值。
```
unlink(path);
if ((fd = creat(path, FILE_MODE)) < 0)
    err_sys("...");
```
### 如果path是/dev/fd/1，会出现什么情况。
