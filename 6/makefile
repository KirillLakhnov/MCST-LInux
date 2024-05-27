CC = gcc
CFLAGS = 

SRCS = main.c background_info_file.c
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o prg

background_info_file.o: background_info_file.c background_info_file.h
	$(CC) $(CFLAGS) -c background_info_file.c

main.o: main.c background_info_file.h
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean

clean:
	rm -f *.o prg