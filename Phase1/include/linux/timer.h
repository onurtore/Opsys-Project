#ifndef _LINUX_TIMER_H
#define _LINUX_TIMER_H

/*
 * In Linux 2.4, static timers have been removed from the kernel.
 * Timers may be dynamically created and destroyed, and should be initialized
 * by a call to init_timer() upon creation.
 *
 * The "data" field enables use of a common timeout function for several
 * timeouts. You can use this field to distinguish between the different
 * invocations.
 */

#include <linux/config.h>
#include <linux/smp.h>
#include <linux/threads.h>
#include <linux/list.h>
#include <linux/spinlock.h>

/*
 * Event timer code
 */
#define TVN_BITS 6
#define TVR_BITS 8
#define TVN_SIZE (1 << TVN_BITS)
#define TVR_SIZE (1 << TVR_BITS)
#define TVN_MASK (TVN_SIZE - 1)
#define TVR_MASK (TVR_SIZE - 1)

typedef struct tvec_s {
	int index;
	struct list_head vec[TVN_SIZE];
} tvec_t;

typedef struct tvec_root_s {
	int index;
	struct list_head vec[TVR_SIZE];
} tvec_root_t;

#define NOOF_TVECS 5

typedef struct timer_list timer_t;

typedef struct tvec_t_base_s {
	spinlock_t lock;
	unsigned long timer_jiffies;
	volatile timer_t * volatile running_timer;
	tvec_root_t tv1;
	tvec_t tv2;
	tvec_t tv3;
	tvec_t tv4;
	tvec_t tv5;
} tvec_base_t;

/*
 * This is the new and improved way of handling timers.
 *
 * The "data" field is in case you want to use the same
 * timeout function for several timeouts. You can use this
 * to distinguish between the different invocations.
 */
struct timer_list {
	struct list_head list;
	unsigned long expires;
	unsigned long data;
	void (*function)(unsigned long);
	tvec_base_t *base;
};

extern void add_timer(timer_t * timer);
extern int del_timer(timer_t * timer);

#ifdef CONFIG_SMP
extern int del_timer_sync(timer_t * timer);
extern void sync_timers(void);
#define timer_enter(base, t) do { base->running_timer = t; mb(); } while (0)
#define timer_exit(base) do { base->running_timer = NULL; } while (0)
#define timer_is_running(base,t) (base->running_timer == t)
#define timer_synchronize(base,t) while (timer_is_running(base,t)) barrier()
#else
#define del_timer_sync(t)	del_timer(t)
#define sync_timers()		do { } while (0)
#define timer_enter(base,t)          do { } while (0)
#define timer_exit(base)            do { } while (0)
#endif

/*
 * mod_timer is a more efficient way to update the expire field of an
 * active timer (if the timer is inactive it will be activated)
 * mod_timer(a,b) is equivalent to del_timer(a); a->expires = b; add_timer(a).
 * If the timer is known to be not pending (ie, in the handler), mod_timer
 * is less efficient than a->expires = b; add_timer(a).
 */
int mod_timer(timer_t *timer, unsigned long expires);

extern void it_real_fn(unsigned long);

extern void init_timers(void);
extern void run_local_timers(void);

extern tvec_base_t tvec_bases[NR_CPUS];

static inline void init_timer(timer_t * timer)
{
	timer->list.next = timer->list.prev = NULL;
	timer->base = tvec_bases + 0;
}

#define TIMER_DEBUG 0
#if TIMER_DEBUG
# define CHECK_BASE(base) \
	if (base && ((base < tvec_bases) || (base >= tvec_bases + NR_CPUS))) \
		BUG()
#else
# define CHECK_BASE(base)
#endif

static inline int timer_pending(const timer_t * timer)
{
	CHECK_BASE(timer->base);
	return timer->list.next != NULL;
}

/*
 *	These inlines deal with timer wrapping correctly. You are 
 *	strongly encouraged to use them
 *	1. Because people otherwise forget
 *	2. Because if the timer wrap changes in future you wont have to
 *	   alter your driver code.
 *
 * Do this with "<0" and ">=0" to only test the sign of the result. A
 * good compiler would generate better code (and a really good compiler
 * wouldn't care). Gcc is currently neither.
 */
#define time_after(a,b)		((long)(b) - (long)(a) < 0)
#define time_before(a,b)	time_after(b,a)

#define time_after_eq(a,b)	((long)(a) - (long)(b) >= 0)
#define time_before_eq(a,b)	time_after_eq(b,a)

#endif
