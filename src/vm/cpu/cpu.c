#include <stdlib.h>
#include "../ram/ram.h"

typedef struct {
	short ax, bx, cx, dx,
		  cs, ds, es, ss,
		  sp, dp, si, ip;
	} CPUStruct;

void cpuLoop();

void cpuInit(struct RAMStruct* ram) {
	CPUStruct* cpu = malloc(sizeof(CPUStruct));
	//here goes CPU registers initialization to zeros. Nothing interesting. Skip 12 lines, if you don't wanna read this
	cpu->ax = 0;
	cpu->bx = 0;
	cpu->cx = 0;
	cpu->dx = 0;
	cpu->cs = 0;
	cpu->ds = 0;
	cpu->es = 0;
	cpu->ss = 0;
	cpu->sp = 0x1000; // stack maximum position. Placed it like this
	cpu->bp = 0x1001; // from here starts memory of the program. Remember that the program has only 30000 byte as RAM for itself
	cpu->si = 0;
	cpu->ip = PROG_START; // stack + working memory. This constant will be defined in cpu_instructions.h. In fact, it is 0x1000+30000

	cpuLoop();
	ram->fAll(ram);
	}

void cpuLoop(struct RAMStruct* ram, CPUStruct* cpu) {

	}
