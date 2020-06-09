#include "apue.h"
#include <errno.h>
#include <limits.h>
#include <sys/resource.h>

#ifdef OPEN_MAX
static long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif

/*
 * If OPEN_MAX is indeterminate, this might be inadequate.
 */
#define OPEN_MAX_GUESS 256

long open_max(void) {
    struct rlimit rl;

    if (openmax == 0) {
        errno = 0;
        if ((openmax = sysconf(_SC_OPEN_MAX)) < 0L || openmax == LONG_MAX) {
            if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
                err_sys("can't get file limit");
            }
            if (rl.rlim_max == RLIM_INFINITY) {
                openmax = OPEN_MAX_GUESS;
            } else {
                openmax = rl.rlim_max;
            }
        }
    }
    return (openmax);
}

int main(void) {
    long openmax = open_max();
    printf("open max: %ld\n", openmax);
    exit(0);
}