CC = gcc
CFLAGS = 

SRCS = main.c parser.c
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o prg

parser.o: parser.c parser.h
	$(CC) $(CFLAGS) -c parser.c

main.o: main.c parser.h
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean

clean:
	rm -f *.o prg