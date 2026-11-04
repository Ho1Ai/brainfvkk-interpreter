#include "../ram/ram.h"
#ifndef CPU_INITIALIZER
#define CPU_INITIALIZER

typedef struct {
	short ax, bx, cx, dx,
		  cs, ds, es, ss,
		  sp, dp, si, ip;
	} CPU;

void cpuInit(struct RAMStruct* ram);

#endif
