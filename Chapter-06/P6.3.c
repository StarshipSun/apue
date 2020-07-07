#include <sys/utsname.h>
#include "apue.h"

int main()
{
	struct utsname name;
	if (uname(&name) < 0) {
		err_sys("uname error");
	}
	printf("%s: %s\n", "sysname", name.sysname);
	printf("%s: %s\n", "nodename", name.nodename);
	printf("%s: %s\n", "release", name.release);
	printf("%s: %s\n", "version", name.version);
	printf("%s: %s\n", "machine", name.machine);
	printf("%s: %s\n", "__domainname", name.__domainname);
	exit(0);
}

