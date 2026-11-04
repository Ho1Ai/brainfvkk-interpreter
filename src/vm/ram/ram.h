#ifndef RAM_INITIALIZER
#define RAM_INITIALIZER
struct RAMStruct {
	char* mem;
	void(*freeAll) (struct RAMStruct*);
	};

struct RAMStruct* ramInit();

void fAll(struct RAMStruct* memory);
#endif
