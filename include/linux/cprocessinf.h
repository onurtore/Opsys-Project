#include <linux/unistd.h>
#include <errno.h>

extern int errno;

struct prcdata{
	long prio; /* calculated with (20-process'es nice value) */
	long weight; /* calculated with process'es counter value + prio */
	pid_t pid; /* process id*/
	pid_t pidparent; /* process id of parent process*/
	int processcount; /* number of process of owner of current process. */
};

_syscall3(int, cprocessinf, struct prcdata *,data, int, option, long, nicev);
