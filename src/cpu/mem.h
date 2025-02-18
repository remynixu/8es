#ifndef MEM_H
#define MEM_H

#include <stdint.h>

#define MEM_OOB		0xffffffff

extern int mem_read(uint8_t addr);
extern int mem_write(uint8_t addr, uint8_t val);

#endif
