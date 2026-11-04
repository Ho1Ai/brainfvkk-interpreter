CC = gcc
INPUT_FILES = src/main.c
OUTPUT_FILES = build/hibf
VM_I = src/vm/main__starter.c src/vm/ram/ram.c src/vm/cpu/cpu.c
VM_O = build/hvm

make:
	$(CC) $(INPUT_FILES) -o $(OUTPUT_FILES)

build_machine:
	$(CC) $(VM_I) -o $(VM_O)
