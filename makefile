CC = gcc
INPUT_FILES = src/main.c
OUTPUT_FILES = build/hibf

make:
	$(CC) $(INPUT_FILES) -o $(OUTPUT_FILES)
