# Unix环境高级编程随书代码和课后习题

## 环境搭建 Arch

* 安装libbsd-dev

* [源码下载](http://www.apuebook.com/apue3e.html)

* 解压
```
cd apue.3e
make
```

* 将 apue.h、error.c 复制到C语言的默认工作目录 /usr/include/
```
cp ./include/apue.h ./lib/error.c /usr/include
```

* 将 libapue.a 复制到 /usr/lib
```
cp ./lib/libapue.a /usr/lib
```

* 编译
```
gcc filename.c -lapue
```