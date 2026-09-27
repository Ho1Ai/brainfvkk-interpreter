#include <stdio.h>
#include <stdlib.h>

int validateInput(int argc, char** argv) {
	int result = 0; // result shows if everything works correctly or doesn't work in a proper way
	
	if(argc != 2) {
		result = 1;
		goto exit_check;
		}

	FILE* file = fopen(argv[1], "r");
	if(!file) {
		result = 2;
		goto exit_check;
		}

	exit_check:
	return result;
	}

int main(int argc, char** argv) {
	int startValidator = validateInput(argc, argv);
	
	switch(startValidator){
		case 0:
			break;
		case 1:
			printf("Missing a file. Only 1 file is supported");
			goto stop_work;
		case 2:
			printf("File with this name does not exist.");
			goto stop_work;
		}	

	char workspace[30000];

	for (int i = 0 ; i < 30000 ; ++i) {
		workspace[i] = 0;
		}

	FILE* workFileInstance = fopen(argv[1], "r");
	char c;
	int currIndex = 0;
	while((c = fgetc(workFileInstance))!= EOF) {
		if(c == '<') {
			if(currIndex == 0) {
				currIndex = 29999;
				} else {
				currIndex--;
				}
			}

		if(c == '>') {
			if(currIndex == 29999) {
				currIndex = 0;
				} else {
				currIndex++;
				}
			}

		if(c == '+') {
			workspace[currIndex]++;
			}

		if(c == '-') {
			workspace[currIndex]--;
			}

		if(c == '.') {
			putchar(workspace[currIndex]);
			}

		if(c == ',') {
			int sc;
			scanf("%d", &sc);
			workspace[currIndex] = sc;
			}

		if(c == '[') {
			char* loopBody = malloc(sizeof(char));
			int size = 1;
			
			while((c=fgetc(workFileInstance))!=EOF && c != ']') {
				loopBody = realloc(loopBody, sizeof(char)*size);
				loopBody[size-1] = c;
				size++;
				}

			int ILOOP_CATCH_OP_COUNTER = 0; // capsed only because necessary stuff. Max is 60000
			int posFloatingExpansion = 0;
			while (workspace[currIndex]) {
				if(ILOOP_CATCH_OP_COUNTER > 60000) break;

				for (int i = 0 ; i < size ; ++i) {
					char ch = loopBody[i];
					if(ch == '>') {
						if (currIndex + posFloatingExpansion == 29999) {
							posFloatingExpansion = currIndex-29999;
							} else {
							posFloatingExpansion++;
							}
						}

					if(ch == '<') {
						if (currIndex + posFloatingExpansion == 0) {
							posFloatingExpansion = 29999 - currIndex;
							} else {
							posFloatingExpansion--;
							}
						}

					if(ch == '+') {
						workspace[currIndex+posFloatingExpansion]++;
						}

					if(ch == '-') {
						workspace[currIndex+posFloatingExpansion]--;
						}

					if(ch == '.') {
						putchar(workspace[currIndex+posFloatingExpansion]);
						}

					if(ch == ',') {
						int sc;
						scanf("%d", &sc);
						workspace[currIndex+posFloatingExpansion] = sc;
						}
					}

				ILOOP_CATCH_OP_COUNTER++;
				}

			free(loopBody);
			}
		}
	putchar('\n');
	stop_work:
	return 0;
	}
