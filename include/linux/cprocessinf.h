#include <linux/unistd.h>
#include <errno.h>
extern int errno;
_syscall3(int, cprocessinf, struct, prdata *data, int, option, long, nicev);
