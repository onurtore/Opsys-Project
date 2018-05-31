#ifndef _LINUX_SYSCALL_H
#define _LINUX_SYSCALL_H

/*
 * Prototypes for Linux syscalls.
 *
 *  - currently only the syscalls needed for linux-abi are here,
 *	it might be a good idea to collect all in one place.
 *  - maybe this could be automatically generated from some kind of
 *	master file (like BSD's syscalls.master), so it is always coherent
 *	to the actual syscalls (which may as well be arch-specific).
 */

#include <asm/syscall.h>

struct itimerval;
struct msghdr;
struct pollfd;
struct rlimit;
struct timespec;
struct timeval;
struct timezone;
struct sigaction;
struct sockaddr;
struct statfs;


/* fs/exec.c */
extern asmlinkage long	sys_uselib(const char * library);

/* fs/fcntl.c */
extern asmlinkage long	sys_dup2(unsigned int oldfd, unsigned int newfd);
extern asmlinkage long	sys_fcntl(unsigned int fd, unsigned int cmd,
				unsigned long arg);

/* fs/ioctl.c */
extern asmlinkage long	sys_ioctl(unsigned int fd, unsigned int cmd, void *);

/* fs/namei.c */
extern asmlinkage long	sys_mkdir(const char * pathname, int mode);
extern asmlinkage long	sys_mknod(const char * filename, int mode, dev_t dev);
extern asmlinkage long	sys_rename(const char * oldname, const char * newname);

/* fs/open.c */
extern asmlinkage long	sys_access(const char * filename, int mode);                              
extern asmlinkage long	sys_open(const char * filename, int flags, int mode);
extern asmlinkage long	sys_statfs(const char * path, struct statfs * buf);
extern asmlinkage long	sys_fstatfs(unsigned int fd, struct statfs * buf);
extern asmlinkage long	sys_ftruncate(unsigned int fd, unsigned long length);
extern asmlinkage long	sys_ftruncate64(unsigned int fd, loff_t length);
extern asmlinkage long	sys_truncate64(const char * path, loff_t length);
extern asmlinkage long	sys_truncate64(const char * path, loff_t length);

/* fs/read_write.c */
extern asmlinkage off_t	sys_lseek(unsigned int fd, off_t offset,
				unsigned int origin);
extern asmlinkage long	sys_llseek(unsigned int fd, unsigned long offset_high,
				unsigned long offset_low, loff_t * result,
				unsigned int origin);
extern asmlinkage ssize_t sys_read(unsigned int fd, char * buf, size_t count);
extern asmlinkage ssize_t sys_pread(unsigned int fd, char * buf,
				size_t count, loff_t pos);
extern asmlinkage ssize_t sys_pwrite(unsigned int fd, const char * buf,
				size_t count, loff_t pos);

/* fs/readdir.c */
extern asmlinkage int	old_readdir(unsigned int fd, void * dirent,
				unsigned int count);

/* fs/select.c */
extern asmlinkage long	sys_poll(struct pollfd * ufds, unsigned int nfds,
				long timeout);
extern asmlinkage int	sys_select(int, fd_set *, fd_set *, fd_set *,
				struct timeval *);

/* fs/stat.c */
extern asmlinkage long	sys_readlink(const char * path, char * buf,
				int bufsiz);

/* fs/super.c */
extern asmlinkage long	sys_sysfs(int option, unsigned long arg1,
				unsigned long arg2);

/* kernel/exit.c */
extern asmlinkage long	sys_exit(int error_code);

/* kernel/itimer.c */
extern asmlinkage long	sys_getitimer(int which, struct itimerval *value);
extern asmlinkage long	sys_setitimer(int which, struct itimerval *value,
				struct itimerval *ovalue);

/* kernel/time.c */
extern asmlinkage long	sys_gettimeofday(struct timeval *tv,
				struct timezone *tz);
extern asmlinkage long	sys_settimeofday(struct timeval *tv,
				struct timezone *tz);
extern asmlinkage long	sys_stime(int * tptr);
extern asmlinkage long	sys_time(int * tloc);

/* kernel/timer.c */
extern asmlinkage long	sys_nanosleep(struct timespec *rqtp,
				struct timespec *rmtp);

/* kernel/signal.c */
extern asmlinkage long	sys_kill(int pid, int sig);
extern asmlinkage long	sys_rt_sigaction(int sig, const struct sigaction *act,
				struct sigaction *oact, size_t sigsetsize);
extern asmlinkage long	sys_rt_sigpending(sigset_t *set, size_t sigsetsize);
extern asmlinkage long	sys_rt_sigprocmask(int how, sigset_t *set,
				sigset_t *oset, size_t sigsetsize);
extern asmlinkage long	sys_rt_sigtimedwait(const sigset_t *uthese,
				siginfo_t *uinfo, const struct timespec *uts,
				size_t sigsetsize);
extern asmlinkage long	sys_sigaltstack(const stack_t *uss, stack_t *uoss);
extern asmlinkage long	sys_sigpending(old_sigset_t *set);
extern asmlinkage long	sys_sigprocmask(int how, old_sigset_t *set,
				old_sigset_t *oset);
extern asmlinkage int	sys_sigsuspend(int history0, int history1,
				old_sigset_t mask);

/* kernel/sys.c */
extern asmlinkage long	sys_gethostname(char *name, int len);
extern asmlinkage long	sys_sethostname(char *name, int len);
extern asmlinkage long	sys_setdomainname(char *name, int len);
extern asmlinkage long	sys_getrlimit(unsigned int resource,
				struct rlimit *rlim);
extern asmlinkage long	sys_setsid(void);
extern asmlinkage long	sys_getsid(pid_t pid);
extern asmlinkage long	sys_getpgid(pid_t pid);
extern asmlinkage long	sys_setpgid(pid_t pid, pid_t pgid);
extern asmlinkage long	sys_getgroups(int gidsetsize, gid_t *grouplist);
extern asmlinkage long	sys_setgroups(int gidsetsize, gid_t *grouplist);

#ifdef CONFIG_UID16
/* kernel/uid16.c */
extern asmlinkage long	sys_setreuid16(old_uid_t ruid, old_uid_t euid);
extern asmlinkage long	sys_setregid16(old_gid_t rgid, old_gid_t egid);
extern asmlinkage long	sys_getgroups16(int gidsetsize, old_gid_t *grouplist);
extern asmlinkage long	sys_setgroups16(int gidsetsize, old_gid_t *grouplist);
#endif /* CONFIG_UID16 */

/* mm/mmap.c */
extern asmlinkage unsigned long sys_brk(unsigned long brk);

/* net/socket.c */
extern asmlinkage long	sys_socket(int family, int type, int protocol);
extern asmlinkage long	sys_socketpair(int family, int type,
				int protocol, int usockvec[2]);
extern asmlinkage long	sys_bind(int fd, struct sockaddr *umyaddr,
				int addrlen);
extern asmlinkage long	sys_listen(int fd, int backlog);
extern asmlinkage long	sys_accept(int fd, struct sockaddr *upeer_sockaddr,
				int *upeer_addrlen);
extern asmlinkage long	sys_connect(int fd, struct sockaddr *uservaddr,
				int addrlen);
extern asmlinkage long	sys_getsockname(int fd, struct sockaddr *usockaddr,
				int *usockaddr_len);
extern asmlinkage long	sys_getpeername(int fd, struct sockaddr *usockaddr,
				int *usockaddr_len);
extern asmlinkage long	sys_sendto(int fd, void * buff, size_t len,
				unsigned flags, struct sockaddr *addr,
				int addr_len);
extern asmlinkage long	sys_send(int fd, void * buff, size_t len,
					unsigned flags);
extern asmlinkage long	sys_recvfrom(int fd, void * ubuf, size_t size,
				unsigned flags, struct sockaddr *addr,
				int *addr_len);
extern asmlinkage long	sys_setsockopt(int fd, int level, int optname,
				char *optval, int optlen);
extern asmlinkage long	sys_getsockopt(int fd, int level, int optname,
				char *optval, int *optlen);
extern asmlinkage long	sys_shutdown(int fd, int how);
extern asmlinkage long	sys_sendmsg(int fd, struct msghdr *msg,
				unsigned flags);
extern asmlinkage long	sys_recvmsg(int fd, struct msghdr *msg,
				unsigned int flags);
extern asmlinkage long	sys_socketcall(int call, unsigned long *args);


#endif /* _LINUX_SYSCALL_H */
