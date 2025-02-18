#include "./reg.h"

uint8_t regtable[REGMAX];

int reg_get(enum reg_id id){
	if(id >= REGMAX){
		return REG_NOTEXIST;
	}
	return regtable[REGMAX];
};

int reg_set(enum reg_id id, uint8_t val){
	if(id >= REGMAX){
		return REG_NOTEXIST;
	}
	return (regtable[id] = val);
}
