#include "apue.h"
#include <errno.h>

void my_setbuf(FILE *stream, char *buf);

void    pr_stdio(const char *, FILE *);

int             is_unbuffered(FILE *);
int             is_linebuffered(FILE *);
int             buffer_size(FILE *);

int main()
{
	char buf[BUFSIZ];

	my_setbuf(stdin, buf);
	pr_stdio("stdin", stdin);
	my_setbuf(stdin, NULL);
	pr_stdio("stdin", stdin);
	printf("my_setbuf success: stdin\n");

	my_setbuf(stdout, buf);
	pr_stdio("stdout", stdout);
	my_setbuf(stdout, NULL);
	pr_stdio("stdout", stdout);
	printf("my_setbuf success: stdout\n");

	my_setbuf(stderr, buf);
	pr_stdio("stderr", stderr);
	my_setbuf(stderr, NULL);
	pr_stdio("stderr", stderr);
	printf("my_setbuf success: stderr\n");

	FILE *fp;
	if ((fp = fopen("/etc/passwd", "r")) == NULL) {
		err_sys("fopen error: /etc/passwd");
	}
	my_setbuf(fp, buf);
	pr_stdio("/etc/passwd", fp);
	my_setbuf(fp, NULL);
	pr_stdio("/etc/passwd", fp);
	printf("my_setbuf success: /etc/passwd\n");

	exit(0);
}

void my_setbuf(FILE *stream, char *buf)
{
	int ret;
	errno = 0;
	if (buf == NULL) {
		ret = setvbuf(stream, buf, _IONBF, 0);
	} else {
		ret = setvbuf(stream, buf, _IOFBF, BUFSIZ);
	}
	
	if (ret != 0) {
		if (errno == 0) {
			err_ret("my_setbuf error");
		} else {
			err_sys("my_setbuf error");
		}
	}
}

/*
 * 参考5.12.c，打印流的缓冲属性
 */

void
pr_stdio(const char *name, FILE *fp)
{
        printf("stream = %s, ", name);

        if (is_unbuffered(fp))
                printf("unbuffered");
        else if (is_linebuffered(fp))
                printf("line buffered");
        else
                printf("fully buffered");
        printf(", buffer size = %d\n", buffer_size(fp));

}

/*
 *  * The following is nonportable.
 *   */

#if defined(_IO_UNBUFFERED)

int
is_unbuffered(FILE *fp)
{
        return(fp->_flags & _IO_UNBUFFERED);
}

int
is_linebuffered(FILE *fp)
{
        return(fp->_flags & _IO_LINE_BUF);
}

int
buffer_size(FILE *fp)
{
        return(fp->_IO_buf_end - fp->_IO_buf_base);
}

#elif defined(__SNBF)

int
is_unbuffered(FILE *fp)
{
        return(fp->_flags & __SNBF);
}

int
is_linebuffered(FILE *fp)
{
        return(fp->_flags & __SLBF);
}

int
buffer_size(FILE *fp)
{
        return(fp->_bf._size);
}

#elif defined(_IONBF)

#ifdef _LP64
#define _flag __pad[4]
#define _ptr __pad[1]
#define _base __pad[2]
#endif

int
is_unbuffered(FILE *fp)
{
        return(fp->_flags & _IONBF);
}

int
is_linebuffered(FILE *fp)
{
        return(fp->_flags & _IOLBF);
}

int
buffer_size(FILE *fp)
{
#ifdef _LP64
        return(fp->_IO_buf_end - fp->_IO_buf_base);
#else
        return(BUFSIZ);
#endif
}

#else

#error unknown stdio implementation!

#endif

