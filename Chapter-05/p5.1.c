#include "apue.h"
#include <errno.h>

void my_setbuf(FILE *stream, char *buf);

int main()
{
	char buf[BUFSIZ];

	my_setbuf(stdin, buf);
	my_setbuf(stdin, NULL);
	printf("my_setbuf success: stdin\n");

	my_setbuf(stdout, buf);
	my_setbuf(stdout, NULL);
	printf("my_setbuf success: stdout\n");

	my_setbuf(stderr, buf);
	my_setbuf(stderr, NULL);
	printf("my_setbuf success: stderr\n");

	FILE *fp;
	if ((fp = fopen("/etc/passwd", "r")) == NULL) {
		err_sys("fopen error: /etc/passwd");
	}
	my_setbuf(fp, buf);
	my_setbuf(fp, NULL);
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
