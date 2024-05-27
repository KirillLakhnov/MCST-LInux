CC = gcc
CFLAGS = 

SRCS = main.c matrix.c
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o prg

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

main.o: main.c matrix.h
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean

clean:
	rm -f *.o prg