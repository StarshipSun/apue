# 第七章 进程环境

## 随书代码

### 7.3.c
```
lin% gcc -o 7.3.out 7.3.c -lapue
lin% ./7.3.out                  
main is done
first exit handler
first exit handler
second exit handler
```
atexit 函数用于注册**终止处理程序（exit handler）**，这些函数由 exit 自动调用。

当调用 exit 时，exit 函数先调用所有 exit handler，调用顺序与注册时相反；然后再调用标准 I/O 清理程序，flush 标准 I/O 流；最后执行 _exit 或者 _Exit。

### 7.10.c
```
lin% gcc -o 7.10.out 7.10.c         不进行任何优化的编译，变量都存放在内存中
lin% ./7.10.out 
in f1():
globval = 95, autoval = 96, regival = 97, volaval = 98, statval = 99
after longjmp:
globval = 95, autoval = 96, regival = 3, volaval = 98, statval = 99
lin% 
lin% gcc -O -o 7.10.out 7.10.c      进行全部优化的编译，autoval 和 regival 都放在寄存器中
lin% ./7.10.out               
in f1():
globval = 95, autoval = 96, regival = 97, volaval = 98, statval = 99
after longjmp:
globval = 95, autoval = 2, regival = 3, volaval = 98, statval = 99
```
调用 longjmp 后，在 main 函数中，具有 volatile 属性的自动变量不会被回滚。全局变量或者静态变量的值在执行 longjmp 时也保持不变。

### 7.11.c
```
lin% gcc -o 7.11.out 7.11.c -lapue
lin% ./7.11.out 
RLIMIT_AS       (infinite)  (infinite)
RLIMIT_CORE     (infinite)  (infinite)
RLIMIT_CPU      (infinite)  (infinite)
RLIMIT_DATA     (infinite)  (infinite)
RLIMIT_FSIZE    (infinite)  (infinite)
RLIMIT_MEMLOCK       65536       65536
RLIMIT_MSGQUEUE      819200      819200
RLIMIT_NICE              0           0
RLIMIT_NOFILE         8192      524288
RLIMIT_NPROC         31548       31548
RLIMIT_RSS      (infinite)  (infinite)
RLIMIT_SIGPENDING       31548       31548
RLIMIT_STACK       8388608  (infinite)
```

## 习题

### P7.1 在 Intel x86 系统上，使用 Linux ，如果执行一个输出 “hello, world” 的程序但不调用 exit 或 return ，则程序的返回代码为 13 （用 shell 检查），解释其原因。
```
lin% gcc -o p7.1.out p7.1.c
lin% ./p7.1.out            
hello, world
lin% echo $?               
13
```
当 main 函数的返回值为 void 类型，并且不调用 exit 或 return 的时候，程序的返回代码才会是 13, 13 是 printf 函数的返回值。

### P7.2 图 7-3 中的 printf 函数的结果何时才被真正输出。
标准输出流是行缓冲，所以输出换行符的时候，结果就被真正输出。

### P7.3 是否有方法不使用（a）参数传递、（b）全局变量这两种方法，将 main 中的参数 argc 和 argv 传递给它所调用的其他函数？
由于 argc 和 argv 的副本不像 environ 一样保存在全局变量中，所以在大多数 UNIX 系统中没有其他方法。

### P7.4 在有些 UNIX 系统实现中执行程序时访问不到其数据段的 0 单元，这是一种有意的安排，为什么？
当 C 程序解引用一个空指针出错时，执行该程序的进程将终止。可以利用这种方式终止进程。（个人理解应该是类似与 Java 中的空指针异常）

### P7.5 用 C 语言的 typedef 为终止处理程序定义了一个新的数据类型 Exitfunc ，使用该类型修改 atexit 的原型。
atexit 的原型：
```
#include <stdlib.h>
int atexit(void (*func)(void));
```
定义如下：
```
typedef void Exitfunc(void);
int atexit(Exitfunc *func);
```

### P7.6 如果用 calloc 分配一个 long 型的数组，数组的初始值是否为 0 ？如果用 calloc 分配一个指针数组，数组的初始值是否为空指针？
```
#include <stdlib.h>
void *calloc(size_t nobj, size_t size);
```
calloc 为指定数量指定长度的对象分配存储空间。该空间的每一位（bit）都初始化为 0。

但是 ISO C 并不保证 0 值与浮点 0 或空指针的值相同。所以 long 型数组的初始值为 0, 但是指针数组的初始值不一定为空指针。

### P7.7 在 7.6 节结尾处 size 命令的输出结果中，为什么没有给出堆和栈的大小？
只有通过 exec 函数执行一个程序时，才会分配堆和栈

### P7.8 为什么 7.7 节中两个文件的大小（879443 和 8378）不等于它们各自文本和数据大小的和？
可执行文件 a.out 包含了用于调试 core 文件的符号表信息。用 strip 命令可以删除这些信息，对两个 a.out 文件执行这条命令，它们的大小减为 798760 和 6200 字节。

### P7.9 为什么 7.7 节中对于一个简单的程序，使用共享库以后其可执行文件的大小变化如此巨大？
没有使用共享库时，可执行文件的大部分都被标准 I/O 库所占用。

### P7.10 在 7.10 节中我们已经说明为什么不能将一个指针返回给一个自动变量，下面的程序是否正确？
```
int f1(int val) {
  int num = 0;
  int *ptr = &num;
  if (val == 0) {
    int val;
    val = 5;
    ptr = &val;
  }
  return (*ptr + 1);
}
```
不正确，自动变量 val 在 if 语句块里面声明，语句块结束之后，变量 val 就不存在了。