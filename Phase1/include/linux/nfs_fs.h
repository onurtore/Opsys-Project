/*
 *  linux/include/linux/nfs_fs.h
 *
 *  Copyright (C) 1992  Rick Sladkey
 *
 *  OS-specific nfs filesystem definitions and declarations
 */

#ifndef _LINUX_NFS_FS_H
#define _LINUX_NFS_FS_H

#include <linux/config.h>
#include <linux/in.h>
#include <linux/mm.h>
#include <linux/pagemap.h>

#include <linux/sunrpc/debug.h>
#include <linux/sunrpc/auth.h>

#include <linux/nfs.h>
#include <linux/nfs2.h>
#include <linux/nfs3.h>
#include <linux/nfs_xdr.h>

/*
 * Enable debugging support for nfs client.
 * Requires RPC_DEBUG.
 */
#ifdef RPC_DEBUG
# define NFS_DEBUG
#endif

/*
 * NFS_MAX_DIRCACHE controls the number of simultaneously cached
 * directory chunks. Each chunk holds the list of nfs_entry's returned
 * in a single readdir call in a memory region of size PAGE_SIZE.
 *
 * Note that at most server->rsize bytes of the cache memory are used.
 */
#define NFS_MAX_DIRCACHE		16

#define NFS_MAX_FILE_IO_BUFFER_SIZE	32768
#define NFS_DEF_FILE_IO_BUFFER_SIZE	4096

/*
 * The upper limit on timeouts for the exponential backoff algorithm.
 */
#define NFS_MAX_RPC_TIMEOUT		(6*HZ)
#define NFS_READ_DELAY			(2*HZ)
#define NFS_WRITEBACK_DELAY		(5*HZ)
#define NFS_WRITEBACK_LOCKDELAY		(60*HZ)
#define NFS_COMMIT_DELAY		(5*HZ)

/*
 * Size of the lookup cache in units of number of entries cached.
 * It is better not to make this too large although the optimum
 * depends on a usage and environment.
 */
#define NFS_LOOKUP_CACHE_SIZE		64

/*
 * superblock magic number for NFS
 */
#define NFS_SUPER_MAGIC			0x6969

static inline struct nfs_inode_info *NFS_I(struct inode *inode)
{
	return (struct nfs_inode_info *)inode->u.generic_ip;
}

#define NFS_FH(inode)			(&NFS_I(inode)->fh)
#define NFS_SERVER(inode)		(&(inode)->i_sb->u.nfs_sb.s_server)
#define NFS_CLIENT(inode)		(NFS_SERVER(inode)->client)
#define NFS_PROTO(inode)		(NFS_SERVER(inode)->rpc_ops)
#define NFS_REQUESTLIST(inode)		(NFS_SERVER(inode)->rw_requests)
#define NFS_ADDR(inode)			(RPC_PEERADDR(NFS_CLIENT(inode)))
#define NFS_CONGESTED(inode)		(RPC_CONGESTED(NFS_CLIENT(inode)))
#define NFS_COOKIEVERF(inode)		(NFS_I(inode)->cookieverf)
#define NFS_READTIME(inode)		(NFS_I(inode)->read_cache_jiffies)
#define NFS_CACHE_CTIME(inode)		(NFS_I(inode)->read_cache_ctime)
#define NFS_CACHE_MTIME(inode)		(NFS_I(inode)->read_cache_mtime)
#define NFS_CACHE_ISIZE(inode)		(NFS_I(inode)->read_cache_isize)
#define NFS_NEXTSCAN(inode)		(NFS_I(inode)->nextscan)
#define NFS_CACHEINV(inode) \
do { \
	NFS_READTIME(inode) = jiffies - NFS_MAXATTRTIMEO(inode) - 1; \
} while (0)
#define NFS_ATTRTIMEO(inode)		(NFS_I(inode)->attrtimeo)
#define NFS_MINATTRTIMEO(inode) \
	(S_ISDIR(inode->i_mode)? NFS_SERVER(inode)->acdirmin \
			       : NFS_SERVER(inode)->acregmin)
#define NFS_MAXATTRTIMEO(inode) \
	(S_ISDIR(inode->i_mode)? NFS_SERVER(inode)->acdirmax \
			       : NFS_SERVER(inode)->acregmax)
#define NFS_ATTRTIMEO_UPDATE(inode)	(NFS_I(inode)->attrtimeo_timestamp)

#define NFS_FLAGS(inode)		(NFS_I(inode)->flags)
#define NFS_REVALIDATING(inode)		(NFS_FLAGS(inode) & NFS_INO_REVALIDATING)
#define NFS_STALE(inode)		(NFS_FLAGS(inode) & NFS_INO_STALE)

#define NFS_FILEID(inode)		(NFS_I(inode)->fileid)
#define NFS_FSID(inode)			(NFS_I(inode)->fsid)

/* Inode Flags */
#define NFS_USE_READDIRPLUS(inode)	((NFS_FLAGS(inode) & NFS_INO_ADVISE_RDPLUS) ? 1 : 0)

/*
 * These are the default flags for swap requests
 */
#define NFS_RPC_SWAPFLAGS		(RPC_TASK_SWAPPER|RPC_TASK_ROOTCREDS)

/* Flags in the RPC client structure */
#define NFS_CLNTF_BUFSIZE	0x0001	/* readdir buffer in longwords */

#define NFS_RW_SYNC		0x0001	/* O_SYNC handling */
#define NFS_RW_SWAP		0x0002	/* This is a swap request */

/*
 * When flushing a cluster of dirty pages, there can be different
 * strategies:
 */
#define FLUSH_AGING		0	/* only flush old buffers */
#define FLUSH_SYNC		1	/* file being synced, or contention */
#define FLUSH_WAIT		2	/* wait for completion */
#define FLUSH_STABLE		4	/* commit to stable storage */

static inline
loff_t page_offset(struct page *page)
{
	return ((loff_t)page->index) << PAGE_CACHE_SHIFT;
}

static inline
unsigned long page_index(struct page *page)
{
	return page->index;
}



/*
 * NFS debug flags
 */
#define NFSDBG_VFS		0x0001
#define NFSDBG_DIRCACHE		0x0002
#define NFSDBG_LOOKUPCACHE	0x0004
#define NFSDBG_PAGECACHE	0x0008
#define NFSDBG_PROC		0x0010
#define NFSDBG_XDR		0x0020
#define NFSDBG_FILE		0x0040
#define NFSDBG_ROOT		0x0080
#define NFSDBG_ALL		0xFFFF

#endif
