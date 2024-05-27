CC = gcc
CFLAGS = 

SRCS = main.c error_check.c
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o prg

error_check.o: error_check.c error_check.h
	$(CC) $(CFLAGS) -c error_check.c

main.o: main.c error_check.h
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean

clean:
	rm -f *.o prg