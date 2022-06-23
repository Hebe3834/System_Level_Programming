all: main.o mystring.o
	gcc -o run main.o mystring.o

main.o: main.c mystring.h
	gcc -c main.c

work08.o: mystring.c mystring.h
	gcc -c mystring.c

run:
	./run

clean:
	rm *~
	rm *.o
