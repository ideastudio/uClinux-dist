#ifndef __M68K_SOFTIRQ_H
#define __M68K_SOFTIRQ_H

#include <asm/atomic.h>
#include <asm/hardirq.h>

#define __cpu_bh_enable(cpu) \
		do { barrier(); local_bh_count(cpu)--; } while (0)
#define cpu_bh_disable(cpu) \
		do { local_bh_count(cpu)++; barrier(); } while (0)

#define local_bh_disable()	cpu_bh_disable(smp_processor_id())
#define __local_bh_enable()	__cpu_bh_enable(smp_processor_id())

#define in_softirq() (local_bh_count(smp_processor_id()) != 0)

#define local_bh_enable() __local_bh_enable()

#endif
