/*
 * uclinux/include/asm-armnommu/arch-S3C44B0X/time.h
 *
 * Copyright (C) 2003 Thomas Eschenbacher <eschenbacher@sympat.de>
 *
 * Setup for 16 bit timer 5, used as system timer.
 *
 */

#ifndef __ASM_ARCH_TIME_H__
#define __ASM_ARCH_TIME_H__

#include <asm/uaccess.h>
#include <asm/io.h>
#include <asm/hardware.h>
#include <asm/arch/timex.h>

extern struct irqaction timer_irq;

extern unsigned long s3c44b0x_gettimeoffset(void);
//extern void s3c44b0x_timer_interrupt(int irq, void *dev_id, struct pt_regs *regs);
static inline  void s3c44b0x_timer_interrupt(int irq, void *dev_id, struct pt_regs *regs)
{
	do_leds();
	do_timer(regs);
}//modified by hzh

/* TODO: THE, 2003-08-13, do timer setup like in eCos */
#define S3C44B0X_TIMER5_PRESCALER 32 

extern __inline__ void setup_timer (void)
{
	u_int32_t tmod;
	u_int32_t period;
	__u32 rw_tmp;

	period = (CONFIG_ARM_CLK/S3C44B0X_TIMER5_PRESCALER)/HZ;
	outl(period, S3C44B0X_TCNTB5);

	tmod=0;
	tmod |= S3C44B0X_TCON_T5_MAN_UPDATE;
	outl(tmod, S3C44B0X_TCON);

	/* initialize the timer period and prescaler */
	rw_tmp  = inl(S3C44B0X_TCFG0);
	rw_tmp &= ~(0xff<<16);
	rw_tmp |= (16-1)<<16;
	outl(rw_tmp, S3C44B0X_TCFG0);		// prescaler = 1/16
	rw_tmp  = inl(S3C44B0X_TCFG1);
	rw_tmp &= ~(0xf<<20);
	rw_tmp |= 0<<20;
	outl(rw_tmp, S3C44B0X_TCFG1);		// mux = 1/2

	/*
	 * @todo do those really need to be function pointers ?
	 */
	gettimeoffset     = s3c44b0x_gettimeoffset;
	timer_irq.handler = s3c44b0x_timer_interrupt;

	/* set up the interrupt vevtor for timer 5 match */
	setup_arm_irq(S3C44B0X_INTERRUPT_TIMER5, &timer_irq);

	/* enable the timer IRQ */
	s3c44b0x_unmask_irq(S3C44B0X_INTERRUPT_TIMER5);

	/* let timer 5 run... */
	tmod=0;
	tmod |= S3C44B0X_TCON_T5_AUTO;
	tmod |= S3C44B0X_TCON_T5_START;
	outl(tmod, S3C44B0X_TCON);
}

#endif /* __ASM_ARCH_TIME_H__ */
