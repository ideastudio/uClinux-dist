#ifndef _NIOS_SEMAPHORE_H
#define _NIOS_SEMAPHORE_H

/* Dinky, good for nothing, just barely irq safe, Nios semaphores.
 *
 * I'll write better ones later.
 */

#include <asm/atomic.h>

struct semaphore {
	atomic_t count;
	atomic_t waking;
	int lock;
	struct wait_queue * wait;
};

#define MUTEX ((struct semaphore) { 1, 0, 0, NULL })
#define MUTEX_LOCKED ((struct semaphore) { 0, 0, 0, NULL })

extern void __down(struct semaphore * sem);
extern int __down_interruptible(struct semaphore * sem);
extern void __up(struct semaphore * sem);

/*
 * This isn't quite as clever as the x86 side, but the gp register
 * makes things a bit more complicated on the alpha..
 */
extern inline void down(struct semaphore * sem)
{
	if (atomic_dec_return(&sem->count) < 0)
		__down(sem);
}

extern inline int down_interruptible(struct semaphore * sem)
{
	int ret = 0;
	if(atomic_dec_return(&sem->count) < 0)
		ret = __down_interruptible(sem);
	return ret;
}

extern inline void up(struct semaphore * sem)
{
	if (atomic_inc_return(&sem->count) <= 0)
		__up(sem);
}	

/*
 * Primitives to spin on a lock.  Needed only for SMP version.
 */
extern inline void get_buzz_lock(int *lock_ptr)
{
#ifdef __SMP__
        while (xchg(lock_ptr,1) != 0) ;
#endif
} /* get_buzz_lock */

extern inline void give_buzz_lock(int *lock_ptr)
{
#ifdef __SMP__
        *lock_ptr = 0 ;
#endif
} /* give_buzz_lock */

#endif /* !(_NIOS_SEMAPHORE_H) */

