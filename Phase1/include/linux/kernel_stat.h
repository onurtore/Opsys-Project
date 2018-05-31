#ifndef _LINUX_KERNEL_STAT_H
#define _LINUX_KERNEL_STAT_H

#include <linux/config.h>
#include <asm/irq.h>
#include <linux/smp.h>
#include <linux/threads.h>

/*
 * 'kernel_stat.h' contains the definitions needed for doing
 * some kernel statistics (CPU usage, context switches ...),
 * used by rstatd/perfmeter
 */

#define DK_MAX_MAJOR 99
#define DK_MAX_DISK 16

struct kernel_stat {
	unsigned int per_cpu_user[NR_CPUS],
	             per_cpu_nice[NR_CPUS],
	             per_cpu_system[NR_CPUS];
	unsigned int dk_drive[DK_MAX_MAJOR][DK_MAX_DISK];
	unsigned int dk_drive_rio[DK_MAX_MAJOR][DK_MAX_DISK];
	unsigned int dk_drive_wio[DK_MAX_MAJOR][DK_MAX_DISK];
	unsigned int dk_drive_rblk[DK_MAX_MAJOR][DK_MAX_DISK];
	unsigned int dk_drive_wblk[DK_MAX_MAJOR][DK_MAX_DISK];
	unsigned int pgpgin, pgpgout;
	unsigned int pswpin, pswpout;
#if !defined(CONFIG_ARCH_S390)
	unsigned int irqs[NR_CPUS][NR_IRQS];
#endif
	unsigned int ipackets, opackets;
	unsigned int ierrors, oerrors;
	unsigned int collisions;
	unsigned int context_swtch;
	unsigned int context_swtch_cross;
	unsigned int nr_free_pending;
	unsigned int nr_allocated;
	unsigned int nr_idle_input_pending;
	unsigned int nr_output_space_pending;
	unsigned int nr_work_pending;
	unsigned int nr_input_pending;
	unsigned int nr_cachemiss_pending;
	unsigned int nr_secondary_pending;
	unsigned int nr_output_pending;
	unsigned int nr_redirect_pending;
	unsigned int nr_postpone_pending;
	unsigned int nr_finish_pending;
	unsigned int nr_userspace_pending;
	unsigned int static_lookup_cachemisses;
	unsigned int static_sendfile_cachemisses;
	unsigned int user_lookup_cachemisses;
	unsigned int user_fetch_cachemisses;
	unsigned int user_sendobject_cachemisses;
	unsigned int user_sendobject_write_misses;
	unsigned int user_sendbuf_cachemisses;
	unsigned int user_sendbuf_write_misses;
#define URL_HIST_SIZE 1000
	unsigned int url_hist_hits[URL_HIST_SIZE];
	unsigned int url_hist_misses[URL_HIST_SIZE];
	unsigned int input_fastpath;
	unsigned int input_slowpath;
	unsigned int inputqueue_got_packet;
	unsigned int inputqueue_no_packet;
	unsigned int nr_keepalive_optimized;

	unsigned int parse_static_incomplete;
	unsigned int parse_static_redirect;
	unsigned int parse_static_cachemiss;
	unsigned int parse_static_nooutput;
	unsigned int parse_static_normal;
	unsigned int parse_dynamic_incomplete;
	unsigned int parse_dynamic_redirect;
	unsigned int parse_dynamic_cachemiss;
	unsigned int parse_dynamic_nooutput;
	unsigned int parse_dynamic_normal;
	unsigned int complete_parsing;

	unsigned int nr_keepalive_reqs;
	unsigned int nr_nonkeepalive_reqs;
#define KEEPALIVE_HIST_SIZE 100
	unsigned int keepalive_hist[KEEPALIVE_HIST_SIZE];
};


extern struct kernel_stat kstat;

#if !defined(CONFIG_ARCH_S390)
/*
 * Number of interrupts per specific IRQ source, since bootup
 */
static inline int kstat_irqs (int irq)
{
	int i, sum=0;

	for (i = 0 ; i < smp_num_cpus ; i++)
		sum += kstat.irqs[cpu_logical_map(i)][irq];

	return sum;
}
#endif

#endif /* _LINUX_KERNEL_STAT_H */
