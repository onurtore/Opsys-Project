#ifndef _LINUX_BLKDEV_H
#define _LINUX_BLKDEV_H

#include <linux/major.h>
#include <linux/sched.h>
#include <linux/genhd.h>
#include <linux/tqueue.h>
#include <linux/list.h>

#include <asm/io.h>

struct request_queue;
typedef struct request_queue request_queue_t;
struct elevator_s;
typedef struct elevator_s elevator_t;

/*
 * Ok, this is an expanded form so that we can use the same
 * request for paging requests when that is implemented. In
 * paging, 'bh' is NULL, and the completion is used to wait
 * for the IO to be ready.
 */
struct request {
	struct list_head queue;
	int elevator_sequence;
	struct list_head table;

	volatile int rq_status;	/* should split this into a few status bits */
#define RQ_INACTIVE		(-1)
#define RQ_ACTIVE		1
#define RQ_SCSI_BUSY		0xffff
#define RQ_SCSI_DONE		0xfffe
#define RQ_SCSI_DISCONNECTING	0xffe0

	kdev_t rq_dev;
	int cmd;		/* READ or WRITE */
	int errors;
	unsigned long start_time;
	unsigned long sector;
	unsigned long nr_sectors;
	unsigned long hard_sector, hard_nr_sectors;
	unsigned int nr_segments;
	unsigned int nr_hw_segments;
	unsigned long current_nr_sectors, hard_cur_sectors;
	void * special;
	char * buffer;
	struct completion * waiting;
	struct buffer_head * bh;
	struct buffer_head * bhtail;
	request_queue_t *q;
};

#include <linux/elevator.h>

typedef int (merge_request_fn) (request_queue_t *q, 
				struct request  *req,
				struct buffer_head *bh,
				int);
typedef int (merge_requests_fn) (request_queue_t *q, 
				 struct request  *req,
				 struct request  *req2,
				 int);
typedef void (request_fn_proc) (request_queue_t *q);
typedef request_queue_t * (queue_proc) (kdev_t dev);
typedef int (make_request_fn) (request_queue_t *q, int rw, struct buffer_head *bh);
typedef void (plug_device_fn) (request_queue_t *q, kdev_t device);
typedef void (unplug_device_fn) (void *q);

/*
 * Default nr free requests per queue, ll_rw_blk will scale it down
 * according to available RAM at init time
 */
#define QUEUE_NR_REQUESTS	8192

struct request_queue
{
	/*
	 * the queue request freelist, one for reads and one for writes
	 */
	struct list_head	request_freelist[2];
	struct list_head	pending_freelist[2];
	int			pending_free[2];

	/*
	 * Together with queue_head for cacheline sharing
	 */
	struct list_head	queue_head;
	elevator_t		elevator;

	request_fn_proc		* request_fn;
	merge_request_fn	* back_merge_fn;
	merge_request_fn	* front_merge_fn;
	merge_requests_fn	* merge_requests_fn;
	make_request_fn		* make_request_fn;
	plug_device_fn		* plug_device_fn;
	/*
	 * The queue owner gets to use this for whatever they like.
	 * ll_rw_blk doesn't touch it.
	 */
	void			* queuedata;

	/*
	 * This is used to remove the plug when tq_disk runs.
	 */
	struct tq_struct	plug_tq;

	/*
	 * Boolean that indicates whether this queue is plugged or not.
	 */
	char			plugged;

	struct page		*bounce_limit;

	/*
	 * Boolean that indicates whether current_request is active or
	 * not.
	 */
	char			head_active;

        /*
	 * Boolean, if true then make_request injects one artifical
         * IO error into the next bh that is submitted. Useful for
         * testing the effects of IO errors.
         */
        char                    oneshot_error;
                                                    
                                                    
	/*	
	 * Is meant to protect the queue in the future instead of
	 * io_request_lock
	 */
	spinlock_t		queue_lock;

	/*
	 * Tasks wait here for free request
	 */
	wait_queue_head_t	wait_for_request;
};

extern unsigned long blk_max_low_pfn;

#define BLK_BOUNCE_HIGH		(blk_max_low_pfn * PAGE_SIZE)
#define BLK_BOUNCE_ANY		(~(unsigned long long) 0)

extern void blk_queue_bounce_limit(request_queue_t *, u64);

#ifdef CONFIG_HIGHMEM
extern struct buffer_head *create_bounce(int, struct buffer_head *);
extern inline struct buffer_head *blk_queue_bounce(request_queue_t *q, int rw,
						   struct buffer_head *bh)
{
	if (bh->b_page <= q->bounce_limit)
		return bh;

	return create_bounce(rw, bh);
}
#else
#define blk_queue_bounce(q, rw, bh)	(bh)
#endif

#define bh_phys(bh)		(page_to_phys((bh)->b_page) + bh_offset((bh)))

#define BH_CONTIG(b1, b2)	(bh_phys((b1)) + (b1)->b_size == bh_phys((b2)))
#define BH_PHYS_4G(b1, b2)	((bh_phys((b1)) | 0xffffffff) == ((bh_phys((b2)) + (b2)->b_size - 1) | 0xffffffff))

struct blk_dev_struct {
	/*
	 * queue_proc has to be atomic
	 */
	request_queue_t		request_queue;
	queue_proc		*queue;
	void			*data;
};

struct sec_size {
	unsigned block_size;
	unsigned block_size_bits;
};

/*
 * Used to indicate the default queue for drivers that don't bother
 * to implement multiple queues.  We have this access macro here
 * so as to eliminate the need for each and every block device
 * driver to know about the internal structure of blk_dev[].
 */
#define BLK_DEFAULT_QUEUE(_MAJOR)  &blk_dev[_MAJOR].request_queue

extern struct blk_dev_struct blk_dev[MAX_BLKDEV];
extern void grok_partitions(struct gendisk *dev, int drive, unsigned minors, long size);
extern void register_disk(struct gendisk *dev, kdev_t first, unsigned minors, struct block_device_operations *ops, long size);
extern void generic_make_request(int rw, struct buffer_head * bh);
extern request_queue_t *blk_get_queue(kdev_t dev);
extern inline request_queue_t *__blk_get_queue(kdev_t dev);
extern void blkdev_release_request(struct request *);

/*
 * Access functions for manipulating queue properties
 */
extern void blk_init_queue(request_queue_t *, request_fn_proc *);
extern void blk_cleanup_queue(request_queue_t *);
extern void blk_queue_headactive(request_queue_t *, int);
extern void blk_queue_make_request(request_queue_t *, make_request_fn *);
extern void generic_unplug_device(void *);
extern inline int blk_seg_merge_ok(request_queue_t *, struct buffer_head *,
					struct buffer_head *);

extern int * blk_size[MAX_BLKDEV];

extern int * blksize_size[MAX_BLKDEV];

extern int * hardsect_size[MAX_BLKDEV];

extern int * max_readahead[MAX_BLKDEV];

extern int * max_sectors[MAX_BLKDEV];

extern wait_queue_head_t blk_buffers_wait;
extern atomic_t queued_sectors;
extern int low_queued_sectors;

#define MAX_SEGMENTS 128
#define MAX_SECTORS 255

#define PageAlignSize(size) (((size) + PAGE_SIZE -1) & PAGE_MASK)

#define blkdev_entry_to_request(entry) list_entry((entry), struct request, queue)
#define blkdev_entry_next_request(entry) blkdev_entry_to_request((entry)->next)
#define blkdev_entry_prev_request(entry) blkdev_entry_to_request((entry)->prev)
#define blkdev_next_request(req) blkdev_entry_to_request((req)->queue.next)
#define blkdev_prev_request(req) blkdev_entry_to_request((req)->queue.prev)


extern unsigned int get_hardblocksize(kdev_t dev);

extern void drive_stat_acct (kdev_t dev, int rw,
					unsigned long nr_sectors, int new_io);

static inline int get_hardsect_size(kdev_t dev)
{
	extern int *hardsect_size[];
	if (hardsect_size[MAJOR(dev)] != NULL)
		return hardsect_size[MAJOR(dev)][MINOR(dev)];
	else
		return 512;
}

#define blk_finished_io(nsects) do {			\
	atomic_sub(nsects, &queued_sectors);		\
	if (atomic_read(&queued_sectors) < 0) {		\
		printk("block: queued_sectors < 0\n");	\
		atomic_set(&queued_sectors, 0);		\
	}						\
	if (atomic_read(&queued_sectors) < low_queued_sectors) \
		wake_up(&blk_buffers_wait);		\
} while (0)

#define blk_started_io(nsects)				\
	atomic_add(nsects, &queued_sectors);

#endif

