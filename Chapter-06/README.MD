# 第六章 系统数据文件和信息

## 随书代码

### 6.2.c
```
lin% gcc -o 6.2.out 6.2.c -lapue
lin% ./6.2.out lin
Username: lin
Hashed passphrase: x
User ID: 1000
Group ID: 1000
Real name: 
Home directory: /home/lin
Shell program: /bin/zsh
```

### 6.10.c
```
lin% gcc -o 6.10.out 6.10.c -lapue
lin% ./6.10.out
buffer length 16 is too small
time and date: 09:42:45 AM, Tue Jul 07, 2020
```

## 习题

### [P6.1](./P6.1.c) 如果系统使用阴影文件，那么如何取得加密口令？
```
lin% gcc -o P6.1.out P6.1.c -lapue

lin% ./P6.1.out lin
Username no found or error: Permission denied

root% ./P6.1.out lin
Login name: lin
Encrypted password: $6$1wLeiH8D1Ng5GgoP$AFv3Ozr//4NQscRn0vRrcLaejNhCgJHktm7jdRLZc76O4B5duCN96a2edNWTAe67fHm7fQpGT1lWtu9NGs6Wb1
Date of last change: -1
Min of days between changes: 0
Max of days between changes: 99999
of days before password expires to warn user to change it: 7
of days after password expires until account is disabled: -1
Date when account expires: -1
Reserved: -1
```
使用访问阴影文件的接口，从数据结构 spwd 中获得加密口令。需要有超级用户权限。

### P6.2 假设你有超级用户权限，并且系统使用了阴影口令，重新考虑上一道习题。
可以直接读取阴影文件或者调用读取阴影文件接口

### [P6.3](./P6.3.c) 编写一程序，它调用 uname 并且输出 utsname 结构中的所有字段，将该输出与 uname 命令的输出结果进行比较。
```
lin% gcc -o P6.3.out P6.3.c -lapue
lin% ./P6.3.out
sysname: Linux
nodename: localhost.localdomain
release: 3.10.0-957.el7.x86_64
version: #1 SMP Thu Nov 8 23:39:32 UTC 2018
machine: x86_64
__domainname: (none)

lin% uname -a
Linux localhost.localdomain 3.10.0-957.el7.x86_64 #1 SMP Thu Nov 8 23:39:32 UTC 2018 x86_64 x86_64 x86_64 GNU/Linux
```

### P6.4 计算可由 time_t 数据类型表示的最近时间。如果超出了这一时间将会如何？
根据系统不同 time_t 可能是 long int 或者 int 。如果是 int 存储的话，那么到 2038 年将达到上限，之后将会溢出，时间变成负数。

### [P6.5](./P6.5.c) 编写一程序，获取当前时间，并使用 strftime 将输出结果转换为类似于 date 命令的默认输出。将环境变量 TZ 设置为不同值，观察输出结果。
```
lin% gcc -o P6.5.out P6.5.c

lin% TZ=Asia/Shanghai ./P6.5.out
localtime: CST 2020/07/07 14:34:11 Tue

lin% TZ=America/Adak ./P6.5.out
localtime: HDT 2020/07/06 21:34:15 Mon

lin% TZ=Africa/Abidjan ./P6.5.out
localtime: GMT 2020/07/07 06:34:30 Tue
```
