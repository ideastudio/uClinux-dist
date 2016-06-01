/*
 *  linux/arch/armnommu/mach-S3C44B0X/arch.c
 *
 *  Copyright (C) 2003 Thomas Eschenbacher <eschenbacher@sympat.de>
 *
 *  Architecture specific fixups.  This is where any
 *  parameters in the params struct are fixed up, or
 *  any additional architecture specific information
 *  is pulled from the params struct.
 */
#include <linux/tty.h>
#include <linux/delay.h>
#include <linux/pm.h>
#include <linux/init.h>

#include <asm/elf.h>
#include <asm/setup.h>
#include <asm/mach-types.h>
#include <asm/mach/arch.h>

extern void genarch_init_irq(void);

MACHINE_START(S3C44B0X, "S3C44B0X")
       MAINTAINER("Thomas Eschenbacher")
       INITIRQ(genarch_init_irq)
       SOFT_REBOOT
MACHINE_END


void arch_hard_reset(void)
{
	/*
	 * @todo activate the hardware reset
	 * 
	 */
	while (1) {};
}

void setup_irq(void)
{
	/*set pins to accept irq's and trigger system events
	 * 
	 * 
	 */
	
	//val32=inl(S3C44B0X_INTMOD);
	//outl((val32&0xF7FFFFF), S3C44B0X_INTMOD); /* normal IRQ */
	//val32=inl(S3C44B0X_EXTINT);
	//outl((val32&0xFFFF8FFF)|0x2000, S3C44B0X_EXTINT); /*falling edge */
	//val32=inl(S3C44B0X_PCONG);
	//outl(val32 | 0xC0, S3C44B0X_PCONG); /* use Port G pin 3 as ext int 3 */
	
}
