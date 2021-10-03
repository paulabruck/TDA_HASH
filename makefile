VALGRIND_FLAGS=--leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=2
CC = gcc
CFLAGS =-g -O0 -Wall -Werror -std=c99 -I cabeceras

all: valgrind

minidemo: hash.c hash_minidemo.c
	$(CC) $(CFLAGS) hash.c hash_minidemo.c -o hash_minidemo 2>&1

pruebas: hash.c hash_pruebas.c
	$(CC) $(CFLAGS) hash.c hash_pruebas.c -o pruebas 2>&1

valgrind: pruebas
	valgrind $(VALGRIND_FLAGS) ./pruebas 2>&1

.PHONY: clean
clean:
	rm -f hash_minidemo
	rm -f pruebas
