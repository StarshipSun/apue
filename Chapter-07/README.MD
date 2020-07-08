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