project: p2.o p3.o pmenu.o
	 cc p2.o p3.o pmenu.o -o project
p2.o: 	 p2.c p2.h
	 cc -c p2.c
p3.o:    p3.c p3.h
	 cc -c p3.c
pmenu.o: pmenu.c pmenu.h
	 cc -c pmenu.c
