#include <linux/cprocessinf.h>
#include <linux/types.h>
#include <asm/current.h>
#include <linux/sched.h>
#include <asm/uaccess.h>

struct prcdata{
	long prio; /* calculated with (20-process'es nice value) */
	long weight; /* calculated with process'es counter value + prio */
	pid_t pid; /* process id*/
	pid_t pidparent; /* process id of parent process*/
	int processcount; /* number of process of owner of current process. */
};
asmlinkage int sys_cprocessinf(struct prdata *data, int option, long nicev){
	
	if(option==200){
		cli();
		struct prdata kernelstructure;
		copy_from_user(&kernelstructure, data, sizeof(struct prdata));
		kernelstructure.pid = current->pid;
		kernelstructure.processcount = current->p_pptr->counter;
		kernelstructure.pidparent = current->p_pptr;
		kernelstructure.prio = 20-(current->nice);
		kernelstructure.weight = (current->counter) + (data->prio);
		copy_to_user(data, &kernelstructure, sizeof(struct prdata));
		sti();	
	}
	else if(option==100){
		current->nice = nicev; /*Fuck you Berk*/
	}
	else
		return -1;
	
	return 0;
}
