# makefile
.PHONY: test
all:	main.o permarray.o
	gcc main.o permarray.o -o permute_array
main.o:	main.c
	gcc -c main.c
permarray.o: permarray.c
	     gcc -c permarray.c
test: 	./test_permute_array.sh