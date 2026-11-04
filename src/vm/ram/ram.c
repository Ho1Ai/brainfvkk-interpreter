#include <stdlib.h>
struct RAMStruct {
	char* mem;
	void(*freeAll) (struct RAMStruct*);
	};

struct RAMStruct* ramInit() {
	struct RAMStruct* new = malloc(sizeof(struct RAMStruct));
	new->mem = malloc(sizeof(char)*65536); // 2^16, btw. Why: cuz I need a 16-bit CPU for this purpose
	return new;
	}

void fAll(struct RAMStruct* ram) {
	free(ram->mem);
	free(ram);
	}
