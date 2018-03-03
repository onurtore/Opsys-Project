/*
 * include/asm-ppc/cpc700.h
 * 
 * Header file for IBM CPC700 Host Bridge, et. al.
 *
 * Author: Mark A. Greer
 *         mgreer@mvista.com
 *
 * Copyright 2000-2002 MontaVista Software Inc.
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 *
 * THIS  SOFTWARE  IS PROVIDED   ``AS  IS'' AND   ANY  EXPRESS OR   IMPLIED
 * WARRANTIES,   INCLUDING, BUT NOT  LIMITED  TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
 * NO  EVENT  SHALL   THE AUTHOR  BE    LIABLE FOR ANY   DIRECT,  INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED   TO, PROCUREMENT OF  SUBSTITUTE GOODS  OR SERVICES; LOSS OF
 * USE, DATA,  OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN  CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * You should have received a copy of the  GNU General Public License along
 * with this program; if not, write  to the Free Software Foundation, Inc.,
 * 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*
 * This file contains the defines and macros for the IBM CPC700 host bridge,
 * memory controller, PIC, UARTs, IIC, and Timers.
 */

#ifndef	_ASMPPC_CPC700_H
#define	_ASMPPC_CPC700_H

#include <linux/stddef.h>
#include <linux/types.h>
#include <linux/init.h>

#define CPC700_OUT_32(a,d)  (*(u_int *)a = d)
#define CPC700_IN_32(a)     (*(u_int *)a)

/*
 * PCI Section
 */
#define CPC700_PCI_CONFIG_ADDR          0xfec00000
#define CPC700_PCI_CONFIG_DATA          0xfec00004

#define CPC700_PMM0_LOCAL		0xff400000
#define CPC700_PMM0_MASK_ATTR		0xff400004
#define CPC700_PMM0_PCI_LOW		0xff400008
#define CPC700_PMM0_PCI_HIGH		0xff40000c
#define CPC700_PMM1_LOCAL		0xff400010
#define CPC700_PMM1_MASK_ATTR		0xff400014
#define CPC700_PMM1_PCI_LOW		0xff400018
#define CPC700_PMM1_PCI_HIGH		0xff40001c
#define CPC700_PMM2_LOCAL		0xff400020
#define CPC700_PMM2_MASK_ATTR		0xff400024
#define CPC700_PMM2_PCI_LOW		0xff400028
#define CPC700_PMM2_PCI_HIGH		0xff40002c
#define CPC700_PTM1_MEMSIZE		0xff400030
#define CPC700_PTM1_LOCAL		0xff400034
#define CPC700_PTM2_MEMSIZE		0xff400038
#define CPC700_PTM2_LOCAL		0xff40003c

/*
 * PIC Section
 *
 * IBM calls the CPC700's programmable interrupt controller the Universal
 * Interrupt Controller or UIC.
 */

/*
 * UIC Register Addresses.
 */
#define	CPC700_UIC_UICSR		0xff500880	/* Status Reg (Rd/Clr)*/
#define	CPC700_UIC_UICSRS		0xff500884	/* Status Reg (Set) */
#define	CPC700_UIC_UICER		0xff500888	/* Enable Reg */
#define	CPC700_UIC_UICCR		0xff50088c	/* Critical Reg */
#define	CPC700_UIC_UICPR		0xff500890	/* Polarity Reg */
#define	CPC700_UIC_UICTR		0xff500894	/* Trigger Reg */
#define	CPC700_UIC_UICMSR		0xff500898	/* Masked Status Reg */
#define	CPC700_UIC_UICVR		0xff50089c	/* Vector Reg */
#define	CPC700_UIC_UICVCR		0xff5008a0	/* Vector Config Reg */

#define	CPC700_UIC_UICER_ENABLE		0x00000001	/* Enable an IRQ */

#define	CPC700_UIC_UICVCR_31_HI		0x00000000	/* IRQ 31 hi priority */
#define	CPC700_UIC_UICVCR_0_HI		0x00000001	/* IRQ 0 hi priority */
#define CPC700_UIC_UICVCR_BASE_MASK	0xfffffffc
#define CPC700_UIC_UICVCR_ORDER_MASK	0x00000001

/* Specify value of a bit for an IRQ. */
#define	CPC700_UIC_IRQ_BIT(i)		((0x00000001) << (31 - (i)))

/*
 * UIC Exports...
 */
extern struct hw_interrupt_type cpc700_pic;
extern unsigned int cpc700_irq_assigns[32][2];
 
extern void __init cpc700_init_IRQ(void);
extern int cpc700_get_irq(struct pt_regs *);

#endif	/* _ASMPPC_CPC700_H */
