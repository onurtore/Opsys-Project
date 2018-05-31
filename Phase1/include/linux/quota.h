/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Robert Elz at The University of Melbourne.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *   This product includes software developed by the University of
 *   California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Version: $Id: quota.h,v 1.3 2002/02/10 23:40:33 arjanv Exp $
 */

#ifndef _LINUX_QUOTA_
#define _LINUX_QUOTA_

#include <linux/errno.h>
#include <linux/types.h>
#include <asm/posix_types.h>

typedef __kernel_uid32_t qid_t;	/* Type in which we store ids in memory */
typedef __u64 qsize_t;		/* Type in which we store size limitations */

#define MAXQUOTAS 2
#define USRQUOTA  0		/* element used for user quotas */
#define GRPQUOTA  1		/* element used for group quotas */

/*
 * Definitions for the default names of the quotas files.
 */
#define INITQFNAMES { \
	"user",    /* USRQUOTA */ \
	"group",   /* GRPQUOTA */ \
	"undefined", \
}

/*
 * Definitions of magics and versions of current quota files
 */
#define INITQMAGICS {\
	0xd9c01f11,	/* USRQUOTA */\
	0xd9c01927	/* GRPQUOTA */\
}

#define INITQVERSIONS {\
	0,		/* USRQUOTA */\
	0		/* GRPQUOTA */\
}

#define QUOTAFILENAME "aquota"
#define QUOTAGROUP "staff"

/* Size of blocks in which are counted size limits */
#define QUOTABLOCK_BITS 10
#define QUOTABLOCK_SIZE (1 << QUOTABLOCK_BITS)

/* Conversion routines from and to quota blocks */
#define qb2kb(x) ((x) << (QUOTABLOCK_BITS-10))
#define kb2qb(x) ((x) >> (QUOTABLOCK_BITS-10))
#define toqb(x) (((x) + QUOTABLOCK_SIZE - 1) >> QUOTABLOCK_BITS)

/*
 * Command definitions for the 'quotactl' system call.
 * The commands are broken into a main command defined below
 * and a subcommand that is used to convey the type of
 * quota that is being manipulated (see above).
 */
#define SUBCMDMASK  0x00ff
#define SUBCMDSHIFT 8
#define QCMD(cmd, type)  (((cmd) << SUBCMDSHIFT) | ((type) & SUBCMDMASK))

#define Q_QUOTAON  0x0100	/* enable quotas */
#define Q_QUOTAOFF 0x0200	/* disable quotas */
/* GETQUOTA, SETQUOTA and SETUSE which were at 0x0300-0x0500 has now other parameteres */
#define Q_SYNC     0x0600	/* sync disk copy of a filesystems quotas */
#define Q_SETQLIM  0x0700	/* set limits */
/* GETSTATS at 0x0800 is now longer... */
#define Q_GETINFO  0x0900	/* get info about quotas - graces, flags... */
#define Q_SETINFO  0x0A00	/* set info about quotas */
#define Q_SETGRACE 0x0B00	/* set inode and block grace */
#define Q_SETFLAGS 0x0C00	/* set flags for quota */
#define Q_GETQUOTA 0x0D00	/* get limits and usage */
#define Q_SETQUOTA 0x0E00	/* set limits and usage */
#define Q_SETUSE   0x0F00	/* set usage */
/* 0x1000 used by old RSQUASH */
#define Q_GETSTATS 0x1100	/* get collected stats */

/*
 * The following structure defines the format of the disk quota file
 * (as it appears on disk) - the file is a hash table whose entries points
 * to blocks of these structures.
 */
struct disk_dqblk {
	__u32 dqb_id;		/* id this quota applies to */
	__u32 dqb_ihardlimit;	/* absolute limit on allocated inodes */
	__u32 dqb_isoftlimit;	/* preferred inode limit */
	__u32 dqb_curinodes;	/* current # allocated inodes */
	__u32 dqb_bhardlimit;	/* absolute limit on disk space (in QUOTABLOCK_SIZE) */
	__u32 dqb_bsoftlimit;	/* preferred limit on disk space (in QUOTABLOCK_SIZE) */
	__u64 dqb_curspace;	/* current space occupied (in bytes) */
	__u64 dqb_btime;	/* time limit for excessive disk use */
	__u64 dqb_itime;	/* time limit for excessive inode use */
};

/* This is in-memory copy of quota block. See meaning of entries above */
struct mem_dqblk {
	unsigned int dqb_ihardlimit;
	unsigned int dqb_isoftlimit;
	unsigned int dqb_curinodes;
	unsigned int dqb_bhardlimit;
	unsigned int dqb_bsoftlimit;
	qsize_t dqb_curspace;
	__kernel_time_t dqb_btime;
	__kernel_time_t dqb_itime;
};

/*
 * Here are header structures as written on disk and their in-memory copies
 */
/* First generic header */
struct disk_dqheader {
	__u32 dqh_magic;	/* Magic number identifying file */
	__u32 dqh_version;	/* File version */
};

/* Header with type and version specific information */
struct disk_dqinfo {
	__u32 dqi_bgrace;	/* Time before block soft limit becomes hard limit */
	__u32 dqi_igrace;	/* Time before inode soft limit becomes hard limit */
	__u32 dqi_flags;	/* Flags for quotafile (DQF_*) */
	__u32 dqi_blocks;	/* Number of blocks in file */
	__u32 dqi_free_blk;	/* Number of first free block in the list */
	__u32 dqi_free_entry;	/* Number of block with at least one free entry */
};

/* Inmemory copy of version specific information */
struct mem_dqinfo {
	unsigned int dqi_bgrace;
	unsigned int dqi_igrace;
	unsigned int dqi_flags;
	unsigned int dqi_blocks;
	unsigned int dqi_free_blk;
	unsigned int dqi_free_entry;
};

/* Flags for version specific files */
#define DQF_MASK  0x0000	/* Mask for all valid ondisk flags */


/*
 *  Structure of header of block with quota structures. It is padded to 16 bytes so
 *  there will be space for exactly 18 quota-entries in a block
 */
struct disk_dqdbheader {
	__u32 dqdh_next_free;	/* Number of next block with free entry */
	__u32 dqdh_prev_free;	/* Number of previous block with free entry */
	__u16 dqdh_entries;	/* Number of valid entries in block */
	__u16 dqdh_pad1;
	__u32 dqdh_pad2;
};

#define DQINFOOFF	sizeof(struct disk_dqheader)	/* Offset of info header in file */
#define DQBLKSIZE_BITS	10
#define DQBLKSIZE	(1 << DQBLKSIZE_BITS)	/* Size of block with quota structures */
#define DQTREEOFF	1		/* Offset of tree in file in blocks */
#define DQTREEDEPTH	4		/* Depth of quota tree */
#define DQSTRINBLK	((DQBLKSIZE - sizeof(struct disk_dqdbheader)) / sizeof(struct disk_dqblk))	/* Number of entries in one blocks */

struct dqstats {
	__u32 lookups;
	__u32 drops;
	__u32 reads;
	__u32 writes;
	__u32 cache_hits;
	__u32 allocated_dquots;
	__u32 free_dquots;
	__u32 syncs;
	__u32 version;
};


#endif /* _QUOTA_ */
