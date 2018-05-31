/*
 *	Definitions for the 'struct sk_buff' memory handlers.
 *
 *	Authors:
 *		Alan Cox, <gw4pts@gw4pts.ampr.org>
 *		Florian La Roche, <rzsfl@rz.uni-sb.de>
 *
 *	This program is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU General Public License
 *	as published by the Free Software Foundation; either version
 *	2 of the License, or (at your option) any later version.
 */
 
#ifndef _LINUX_SKBUFF_H
#define _LINUX_SKBUFF_H

#include <linux/config.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/time.h>
#include <linux/cache.h>

#include <asm/types.h>
#include <linux/spinlock.h>
#include <linux/mm.h>
#include <linux/highmem.h>

#define HAVE_ALLOC_SKB		/* For the drivers to know */
#define HAVE_ALIGNABLE_SKB	/* Ditto 8)		   */
#define SLAB_SKB 		/* Slabified skbuffs 	   */

#define CHECKSUM_NONE 0
#define CHECKSUM_HW 1
#define CHECKSUM_UNNECESSARY 2

#define SKB_DATA_ALIGN(X)	(((X) + (SMP_CACHE_BYTES-1)) & ~(SMP_CACHE_BYTES-1))
#define SKB_MAX_HEAD(X)		((PAGE_SIZE - (X) - sizeof(struct skb_shared_info))&~(SMP_CACHE_BYTES-1))

/* A. Checksumming of received packets by device.
 *
 *	NONE: device failed to checksum this packet.
 *		skb->csum is undefined.
 *
 *	UNNECESSARY: device parsed packet and wouldbe verified checksum.
 *		skb->csum is undefined.
 *	      It is bad option, but, unfortunately, many of vendors do this.
 *	      Apparently with secret goal to sell you new device, when you
 *	      will add new protocol to your host. F.e. IPv6. 8)
 *
 *	HW: the most generic way. Device supplied checksum of _all_
 *	    the packet as seen by netif_rx in skb->csum.
 *	    NOTE: Even if device supports only some protocols, but
 *	    is able to produce some skb->csum, it MUST use HW,
 *	    not UNNECESSARY.
 *
 * B. Checksumming on output.
 *
 *	NONE: skb is checksummed by protocol or csum is not required.
 *
 *	HW: device is required to csum packet as seen by hard_start_xmit
 *	from skb->h.raw to the end and to record the checksum
 *	at skb->h.raw+skb->csum.
 *
 *	Device must show its capabilities in dev->features, set
 *	at device setup time.
 *	NETIF_F_HW_CSUM	- it is clever device, it is able to checksum
 *			  everything.
 *	NETIF_F_NO_CSUM - loopback or reliable single hop media.
 *	NETIF_F_IP_CSUM - device is dumb. It is able to csum only
 *			  TCP/UDP over IPv4. Sigh. Vendors like this
 *			  way by an unknown reason. Though, see comment above
 *			  about CHECKSUM_UNNECESSARY. 8)
 *
 *	Any questions? No questions, good. 		--ANK
 */

#ifdef __i386__
#define NET_CALLER(arg) (*(((void**)&arg)-1))
#else
#define NET_CALLER(arg) __builtin_return_address(0)
#endif

#ifdef CONFIG_NETFILTER
struct nf_conntrack {
	atomic_t use;
	void (*destroy)(struct nf_conntrack *);
};

struct nf_ct_info {
	struct nf_conntrack *master;
};
#endif

struct sk_buff_head {
	/* These two members must be first. */
	struct sk_buff	* next;
	struct sk_buff	* prev;

	__u32		qlen;
	spinlock_t	lock;
};

struct sk_buff;

#define MAX_SKB_FRAGS 6

typedef struct skb_frag_struct skb_frag_t;

struct skb_frag_struct
{
	struct page *page;
	__u16 page_offset;
	__u16 size;
};

/* This data is invariant across clones and lives at
 * the end of the header data, ie. at skb->end.
 */
struct skb_shared_info {
	atomic_t	dataref;
	unsigned int	nr_frags;
	struct sk_buff	*frag_list;
	skb_frag_t	frags[MAX_SKB_FRAGS];
};

struct sk_buff {
	/* These two members must be first. */
	struct sk_buff	* next;			/* Next buffer in list 				*/
	struct sk_buff	* prev;			/* Previous buffer in list 			*/

	struct sk_buff_head * list;		/* List we are on				*/
	struct sock	*sk;			/* Socket we are owned by 			*/
	struct timeval	stamp;			/* Time we arrived				*/
	struct net_device	*dev;		/* Device we arrived on/are leaving by		*/

	/* Transport layer header */
	union
	{
		struct tcphdr	*th;
		struct udphdr	*uh;
		struct icmphdr	*icmph;
		struct igmphdr	*igmph;
		struct iphdr	*ipiph;
		struct spxhdr	*spxh;
		unsigned char	*raw;
	} h;

	/* Network layer header */
	union
	{
		struct iphdr	*iph;
		struct ipv6hdr	*ipv6h;
		struct arphdr	*arph;
		struct ipxhdr	*ipxh;
		unsigned char	*raw;
	} nh;
  
	/* Link layer header */
	union 
	{	
	  	struct ethhdr	*ethernet;
	  	unsigned char 	*raw;
	} mac;

	struct  dst_entry *dst;

	/* 
	 * This is the control buffer. It is free to use for every
	 * layer. Please put your private variables there. If you
	 * want to keep them across layers you have to do a skb_clone()
	 * first. This is owned by whoever has the skb queued ATM.
	 */ 
	char		cb[48];	 

	unsigned int 	len;			/* Length of actual data			*/
 	unsigned int 	data_len;
	unsigned int	csum;			/* Checksum 					*/
	unsigned char 	__unused,		/* Dead field, may be reused			*/
			cloned, 		/* head may be cloned (check refcnt to be sure). */
  			pkt_type,		/* Packet class					*/
  			ip_summed;		/* Driver fed us an IP checksum			*/
	__u32		priority;		/* Packet queueing priority			*/
	atomic_t	users;			/* User count - see datagram.c,tcp.c 		*/
	unsigned short	protocol;		/* Packet protocol from driver. 		*/
	unsigned short	security;		/* Security level of packet			*/
	unsigned int	truesize;		/* Buffer size 					*/

	unsigned char	*head;			/* Head of buffer 				*/
	unsigned char	*data;			/* Data head pointer				*/
	unsigned char	*tail;			/* Tail pointer					*/
	unsigned char 	*end;			/* End pointer					*/

	void 		(*destructor)(struct sk_buff *);	/* Destruct function		*/
#ifdef CONFIG_NETFILTER
	/* Can be used for communication between hooks. */
        unsigned long	nfmark;
	/* Cache info */
	__u32		nfcache;
	/* Associated connection, if any */
	struct nf_ct_info *nfct;
#ifdef CONFIG_NETFILTER_DEBUG
        unsigned int nf_debug;
#endif
#endif /*CONFIG_NETFILTER*/

#if defined(CONFIG_HIPPI)
	union{
		__u32	ifield;
	} private;
#endif

#ifdef CONFIG_NET_SCHED
       __u32           tc_index;               /* traffic control index */
#endif
};

#define SK_WMEM_MAX	65535
#define SK_RMEM_MAX	65535


#endif	/* _LINUX_SKBUFF_H */
