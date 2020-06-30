#include "apue.h"
#include <dirent.h>
#include <limits.h>

static char	*fullpath;
static size_t pathlen;

int
main(int argc, char *argv[])
{
	fullpath = path_alloc(&pathlen);
	printf("PATH_MAX: %d\n", pathlen);

	char *dirname = "alonglonglonglonglonglonglonglonglonglonglonglongname";
	char src[4096];

	int i;
	for (i = 0; i < 1000; ++i) {
		if (mkdir(dirname, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP) < 0) {
			err_sys("%3d mkdir error", i);
		}

		if (chdir(dirname) < 0) {
			err_sys("%3d chdir error", i);
		}

		if (getcwd(fullpath, pathlen) == NULL) {
			sprintf(src, "%3d getcwd error", i);
			perror(src);
		} else {
			printf("%3d getcwd success\n", i);
		}
	}
	exit(0);
}
