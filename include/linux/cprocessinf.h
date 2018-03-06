#include <linux/unistd.h>
#include <errno.h>
#include <sys/types.h>
extern int errno;

_syscall3(int, cprocessinf, struct prcdata *,data, int, option, long, nicev);
