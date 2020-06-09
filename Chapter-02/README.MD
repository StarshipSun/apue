# 第二章 UNIX标准及实现

## 随书代码

### 2.5.4.awk 2.5.4.c
```
lin% awk -f 2.5.4.awk > 2.5.4.c     
lin% gcc -o 2.5.4.out 2.5.4.c -lapue
lin% ./2.5.4.out .                  
no symbol for ARG_MAX
ARG_MAX = 2097152
no symbol for ATEXIT_MAX
ATEXIT_MAX = 2147483647
CHARCLASS_NAME_MAX defined to be 2048
CHARCLASS_NAME_MAX = 2048
no symbol for CHILD_MAX
CHILD_MAX = 31557
no symbol for CLOCKTICKSPERSECOND /*clock ticks/second*/
CLOCKTICKSPERSECOND /*clock ticks/second*/ = 100
COLL_WEIGHTS_MAX defined to be 255
COLL_WEIGHTS_MAX = 255
DELAYTIMER_MAX defined to be 2147483647
DELAYTIMER_MAX = 2147483647
HOST_NAME_MAX defined to be 64
HOST_NAME_MAX = 64
IOV_MAX defined to be 1024
IOV_MAX = 1024
LINE_MAX defined to be 2048
LINE_MAX = 2048
LOGIN_NAME_MAX defined to be 256
LOGIN_NAME_MAX = 256
NGROUPS_MAX defined to be 65536
NGROUPS_MAX = 65536
no symbol for OPEN_MAX
OPEN_MAX = 8192
no symbol for PAGESIZE
PAGESIZE = 4096
no symbol for PAGE_SIZE
PAGE_SIZE = 4096
RE_DUP_MAX defined to be 32767
RE_DUP_MAX = 32767
RTSIG_MAX defined to be 32
RTSIG_MAX = 32
no symbol for SEM_NSEMS_MAX
SEM_NSEMS_MAX = (no limit)
SEM_VALUE_MAX defined to be 2147483647
SEM_VALUE_MAX = 2147483647
no symbol for SIGQUEUE_MAX
SIGQUEUE_MAX = 31557
no symbol for STREAM_MAX
STREAM_MAX = 16
no symbol for SYMLOOP_MAX
SYMLOOP_MAX = (no limit)
no symbol for TIMER_MAX
TIMER_MAX = (no limit)
TTY_NAME_MAX defined to be 32
TTY_NAME_MAX = 32
no symbol for TZNAME_MAX
TZNAME_MAX = (no limit)
no symbol for FILESIZEBITS
FILESIZEBITS = 64
no symbol for LINK_MAX
LINK_MAX = 65000
MAX_CANON defined to be 255
MAX_CANON = 255
MAX_INPUT defined to be 255
MAX_INPUT = 255
NAME_MAX defined to be 255
NAME_MAX = 255
PATH_MAX defined to be 4096
PATH_MAX = 4096
PIPE_BUF defined to be 4096
PIPE_BUF = 4096
no symbol for SYMLINK_MAX
SYMLINK_MAX = (no limit)
no symbol for _POSIX_TIMESTAMP_RESOLUTION
no symbol for _PC_TIMESTAMP_RESOLUTION
```