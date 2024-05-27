CC = gcc
CFLAGS = 

SRCS = main.c file_func.c 
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o prg

file_func.o: file_func.c file_func.h
	$(CC) $(CFLAGS) -c file_func.c

main.o: main.c file_func.h
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean

clean:
	rm -f *.o prg
