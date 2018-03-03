/* header file for DIO boards for the HP300 architecture.
 * Maybe this should handle DIO-II later?
 * The general structure of this is vaguely based on how
 * the Amiga port handles Zorro boards.
 * Copyright (C) Peter Maydell 05/1998 <pmaydell@chiark.greenend.org.uk>
 *
 * The board IDs are from the NetBSD kernel, which for once provided
 * helpful comments...
 *
 * This goes with arch/m68k/hp300/dio.c
 */

#ifndef _LINUX_DIO_H
#define _LINUX_DIO_H

/* The DIO boards in a system are distinguished by 'select codes' which 
 * range from 0-63 (DIO) and 132-255 (DIO-II). 
 * The DIO board with select code sc is located at physical address 
 *     0x600000 + sc * 0x10000
 * So DIO cards cover [0x600000-0x800000); the areas [0x200000-0x400000) and
 * [0x800000-0x1000000) are for additional space required by things
 * like framebuffers. [0x400000-0x600000) is for miscellaneous internal I/O.
 * On Linux, this is currently all mapped into the virtual address space
 * at 0xf0000000 on bootup.
 * DIO-II boards are at 0x1000000 + (sc - 132) * 0x400000
 * which is address range [0x1000000-0x20000000) -- too big to map completely,
 * so currently we just don't handle DIO-II boards.  It wouldn't be hard to 
 * do with ioremap() though.
 */

#endif /* ndef _LINUX_DIO_H */
