#include "./cpu/cpu.h"
#include "./ram/ram.h"

int main(int argc, char** argv) { // this does absolutely nothing, except ram_init() and cpu_init(). Also argv contains input file, which removes some needs
	struct RAMStruct* ram = ramInit();
	cpuInit(ram);

	return 0;
	}
