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