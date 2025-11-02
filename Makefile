
CC = gcc
C_FLAGS = -Iinclude -o

SRC = src/main.c
LIB = include/str.c
TARGET = build/main.exe

all:
	$(CC) $(SRC) $(LIB) $(C_FLAGS) $(TARGET)

run:
	@build/main.exe

clean:
	@del build/main.exe

disasm:
	@$(CC) -S $(SRC)