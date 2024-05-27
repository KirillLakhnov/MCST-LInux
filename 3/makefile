CC = gcc
CFLAGS = 

SRCS = main.c sort.c
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o prg

sort.o: sort.c sort.h
	$(CC) $(CFLAGS) -c sort.c

main.o: main.c sort.h
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean

clean:
	rm -f *.o prg