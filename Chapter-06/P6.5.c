#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	time_t t;
	if (time(&t) == -1) {
		perror("time error");
	}

	struct tm* ptr_t = localtime(&t);
	
	char buf[64];
	if (strftime(buf, 64, "%Z %Y/%m/%d %H:%M:%S %a", ptr_t) == 0) {
		printf("strftime error: buffer size too small\n");
	} else {
		printf("localtime: %s\n", buf);
	}
	exit(0);
}
