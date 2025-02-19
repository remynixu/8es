#ifndef CPU_H
#define CPU_H

#include "./reg.h"

struct cpu_state{
	uint8_t regtable[REGMAX];
	uint8_t *mmap_base;
	uint8_t mmap_size;
};

extern int cpu_init(struct cpu_state *state);
extern int cpu_run(void);
extern int cpu_halt(void);

#endif
