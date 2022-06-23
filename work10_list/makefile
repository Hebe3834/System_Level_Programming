all: main.o 10_list.o
	gcc -o output main.o 10_list.o

main.o: main.c 10_list.h
	gcc -c main.c

10_list.o: 10_list.c 10_list.h
	gcc -c 10_list.c

run: 
	./output
