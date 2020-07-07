#include <pwd.h>
#include <stddef.h>
#include <string.h>
#include "apue.h"

struct passwd *
getpwnam(const char *name)
{
    struct passwd  *ptr;

    setpwent();
    while ((ptr = getpwent()) != NULL)
        if (strcmp(name, ptr->pw_name) == 0)
            break;		/* found a match */
    endpwent();
    return(ptr);	/* ptr is NULL if no match found */
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: %s Username\n", argv[0]);
	exit(1);
    }

    struct passwd *ptr = getpwnam(argv[1]);
    if (ptr == NULL) {
        err_sys("No match found Username: %s", argv[1]);
    }

    printf("Username: %s\nHashed passphrase: %s\nUser ID: %d\nGroup ID: %d\nReal name: %s\nHome directory: %s\nShell program: %s\n", 
        ptr->pw_name, ptr->pw_passwd, ptr->pw_uid, ptr->pw_gid, ptr->pw_gecos, ptr->pw_dir, ptr->pw_shell);
    return 0;
}
