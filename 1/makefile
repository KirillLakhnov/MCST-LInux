CC = gcc
CFLAGS = -pthread -std=c99

SRCS = main.c mergesort.c
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o prg

mergesort.o: mergesort.c mergesort.h
	$(CC) $(CFLAGS) -c mergesort.c

main.o: main.c mergesort.h
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean

clean:
	rm -f *.o prg