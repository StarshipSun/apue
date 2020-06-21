# 第四章 文件类型

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