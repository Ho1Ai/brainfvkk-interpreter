#include "./cpu.h"
#include "../ram/ram.h"
#ifndef ISA
#define ISA
#define PROG_START 0x1000+30000

void i_0x10 (struct RAMStruct* ram, CPU* cpu_state);

#endif
