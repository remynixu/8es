#include "./cpu.h"
#include "./reg.h"

static struct cpu_state *cpu_state;

static uint8_t cpu_flags;

/* TODO: replace '-1' with enum constant name. */

static int cpu_refresh(void){
	if(reg_set(RID_ACCUMULATOR, cpu_state->regtable[RID_ACCUMULATOR]) != 0){
		return -1;
	}
	if(reg_set(RID_XREGISTER, cpu_state->regtablr[RID_XREGISTER]) != 0){
		return -1;
	}
	if(reg_set(RID_YREGISTER, cpu_state->regtable[RID_YREGISTER]) != 0){
		return -1;
	}
	if(reg_set(RID_CODECOUNTER, cpu_state->regtable[RID_CODECOUNTER]) != 0){
		return -1;
	}
	cpu_flags = 0;
	return 0;
};

int cpu_init(struct cpu_state *state){
	if(state == 0){
		return -1;
	}
	cpu_state = state;
	if(cpu_refresh() != 0){
		return -1;
	}
	return 0;
}

static struct cpu_execinfo{
	uint8_t setflags;
	uint8_t usetflags;
	uint8_t call_index;
};

enum cpu_flag_offset{
	CFO_BRKFLAG = 0
};

static struct cpu_execinfo decodingtable[256] = {
	{
		0,
		0,
		0
	},
	{
		(1 << CFO_BRKFLAG),
		0,
		1
	}
};

static void cet_noop(struct cpu_execinfo *info){
	return;
}

static void cet_halt(struct cpu_execinfo *info){
	cpu_halt();
	return;
}

/* TODO: remove magic */

static void (*exectable[256])(struct cpu_execinfo *) = {
	cet_noop,
	cet_halt
};

static int cpu_exec(struct cpu_execinfo *info){
	if(info == 0){
		return -1;
	}
	if(exectable[info->call_index] == 0){
		return -1;
	}
	exectable[info->call_index](info);
	return 0;
}

int cpu_run(void){
	if(cpu_state == 0){
		return -1;
	}
	while(reg_get(RID_CODECOUNTER) < 256){
		if(cpu_exec(&decodingtable[reg_get(RID_CODECOUNTER)]) != 0){
			return -1;
		}
		if(reg_set(RID_CODECOUNTER, reg_get(RID_CODECOUNTER) + 1) != 0){
			return -1;
		}
	}
	return 0;
}

int cpu_halt(void){
	while(cpu_flags & (1 << CFO_BRKFLAG)){
	}
	return 0;
}
