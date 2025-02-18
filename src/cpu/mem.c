#include "./mem.h"

#define MMAPSIZE	256

static uint8_t mmap[MMAPSIZE];

int mem_read(uint8_t addr){
	if(addr >= MMAPSIZE){
		return MEM_OOB;
	}
	return mmap[addr];
}

int mem_write(uint8_t addr, uint8_t val){
	if(addr >= MMAPSIZE){
		return MEM_OOB;
	}
	return (mmap[addr] = val);
}
