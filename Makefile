CC = gcc
CFLAGS	= -Wall -g
OBJFILES = filme.o main.o interpretador.o conversor.o
LDFLAGS = -lm
TARGET = tp1
all: clear $(OBJFILES) 
	$(CC) $(CFLAGS) $(OBJFILES) -o $(TARGET) $(LDFLAGS)
main.o: main.c
	gcc -Wall -c main.c
filme.o:  filme.c filme.h
	gcc -Wall -c filme.c
interpretador.o: interpretador.c interpretador.h
	gcc -Wall -c interpretador.c
conversor.o: conversor.c conversor.h
	gcc -Wall -c conversor.c $(LDFLAGS)
clear:
	rm -f $(OBJFILES) $(TARGET) *~
