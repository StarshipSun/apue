# 第一章 Unix基础知识

## 随书代码

### 1.4.3.c
```
lin% gcc -o 1.4.3.out 1.4.3.c -lapue 
lin% ./1.4.3.out /home/lin/Desktop/apue/Chapter-01          
..
1.4.3.out
README.MD
.
1.4.3.c 
```

### 1.5.3.c
```
lin% gcc -o 1.5.3.out 1.5.3.c -lapue           
lin% ./1.5.3.out > data  # 重定向输出到data文件
apue linux programming
lin% cat data        
apue linux programming
```

### 1.5.4.c
```
lin% gcc -o 1.5.4.out 1.5.4.c -lapue
lin% ./1.5.4.out                    
this is apue
this is apue
```

### 1.6.2.c
```
lin% gcc -o 1.6.2.out 1.6.2.c -lapue
lin% ./1.6.2.out
hello world from process ID 2025
```

### 1.6.3.c
```
lin% gcc -o 1.6.3.out 1.6.3.c -lapue
lin% ./1.6.3.out                    
% who
lin      tty1         2020-06-08 20:19 (:0)
lin      pts/0        2020-06-08 20:19 (:0)
lin      pts/1        2020-06-08 20:19 (:0)
% pwd
/home/lin/Desktop/apue/Chapter-01
% ls
1.4.3.c  1.4.3.out  1.5.3.c  1.5.3.out  1.5.4.c  1.5.4.out  1.6.2.c  1.6.2.out  1.6.3.c  1.6.3.out  data  README.MD
% %    
```

### 1.7.c
```
lin% gcc -o 1.7.out 1.7.c -lapue
lin% ./1.7.out 
EACCES: Permission denied
./1.7.out: No such file or directory
```

### 1.8.2.c
```
lin% gcc -o 1.8.2.out 1.8.2.c -lapue 
lin% ./1.8.2.out 
uid = 1000, gid = 1000
```

### 1.9.c
```
lin% gcc -o 1.9.out 1.9.c -lapue
lin% ./1.9.out                  
% who
lin      tty1         2020-06-08 20:19 (:0)
lin      pts/0        2020-06-08 20:19 (:0)
lin      pts/1        2020-06-08 20:19 (:0)
% ^Cinterrupt
% %     
```

### 1.10
```
lin% time grep _POSIX_SOURCE */*.h > /dev/null 
grep _POSIX_SOURCE */*.h > /dev/null  0.17s user 0.77s system 45% cpu 2.081 total
```

## 习题

### P1.1 在系统上验证，除根目录外，目录.和..是不同的
```
lin% pwd
/home/lin
lin% ls -lia | grep \\.
 397374 drwx------ 19 lin  lin   4096 Jun  8 20:19 .
 393217 drwxr-xr-x  3 root root  4096 Aug 25  2019 ..
```
```
# cd /
# ls -lia | grep \\.
2 drwxr-xr-x  17 root root       4096 Jun  6 15:09 .
2 drwxr-xr-x  17 root root       4096 Jun  6 15:09 ..
```
-i 打印文件或目录的根节点，在根目录/下，目录.和..相同，其他目录下不同

### P1.3 在1.7节中，perror的参数是用ISO C的属性const定义的，而strerror的整型参数没有用此属性定义，为什么？
```
# <stdio.h>
void perror (const char *__s);

# <string.h>
char *strerror (int __errnum) __THROW;
```
perror的入参是字符串，const修饰表示不允许perror修改其指向字符。
strerror的入参的整型，按值传递，strerror修改了也不会影响到函数的调用方，所以没必要加const。