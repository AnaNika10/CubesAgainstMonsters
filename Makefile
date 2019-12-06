PROGRAM = projekat
CC      = gcc
CFLAGS  = -g -Wall  -std=c99
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS  = -lglut -lGLU -lGL

$(PROGRAM): projekat.o tabla.o figure.o kocka.o pomeranje.o
	$(CC) $(LDFLAGS) -o $(PROGRAM) projekat.o tabla.o figure.o kocka.o pomeranje.o $(LDLIBS)
projekat.o: projekat.c 
	gcc -c $(CFLAGS) -o projekat.o projekat.c $(LIBS)
tabla.o: tabla.c
	gcc -c $(CFLAGS) -o tabla.o tabla.c $(LIBS)
figure.o: figure.c
	gcc -c $(CFLAGS) -o figure.o figure.c $(LIBS)
kocka.o: kocka.c
	gcc -c $(CFLAGS) -o kocka.o kocka.c $(LIBS)
pomeranje.o: pomeranje.c
	gcc -c $(CFLAGS) -o pomeranje.o pomeranje.c $(LIBS)

.PHONY: clean dist

clean:
	-rm *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)
