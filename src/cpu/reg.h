#ifndef REG_H
#define REG_H

#include <stdint.h>

#define REGMAX		4

enum reg_id{
	RID_ACCUMULATOR = 0x00,
	RID_XREGISTER	= 0x01,
	RID_YREGISTER	= 0x02,
	RID_CODECOUNTER	= 0x03
};

#define REG_NOTEXIST	0xffffffff

extern int reg_get(enum reg_id id);
extern int reg_set(enum reg_id id, uint8_t val);

#endif
