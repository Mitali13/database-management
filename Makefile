project: mp.o main.o 
	cc mp.o main.o -o project
mp.o: mp.c mp.h
	cc -c mp.c
main.o: main.c mp.h
	cc -c main.c
