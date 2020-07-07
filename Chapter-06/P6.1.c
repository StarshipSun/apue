#include <shadow.h>
#include "apue.h"

int main(int argc, char* argv[])
{
	if (argc != 2) {
		printf("Usage: %s username\n", argv[0]);
		exit(0);
	}

	struct spwd *ptr = getspnam(argv[1]);
	if (ptr == NULL) {
		perror("Username no found or error");
		exit(0);
	}

	printf("%s: %s\n", "Login name", ptr->sp_namp);
	printf("%s: %s\n", "Encrypted password", ptr->sp_pwdp);
	printf("%s: %ld\n", "Date of last change", ptr->sp_lstchg);
	printf("%s: %ld\n", "Min of days between changes", ptr->sp_min);
	printf("%s: %ld\n", "Max of days between changes", ptr->sp_max);
	printf("%s: %ld\n", "of days before password expires to warn user to change it", ptr->sp_warn);
	printf("%s: %ld\n", "of days after password expires until account is disabled", ptr->sp_inact);
	printf("%s: %ld\n", "Date when account expires", ptr->sp_expire);
	printf("%s: %ld\n", "Reserved", ptr->sp_flag);
	return 0;
}
