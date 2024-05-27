CC = g++
CFLAGS = 

SRCS = main.cpp algorithm.cpp
OBJS = $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o prg

algorithm.o: algorithm.cpp algorithm.hpp
	$(CC) $(CFLAGS) -c algorithm.cpp

main.o: main.cpp algorithm.hpp
	$(CC) $(CFLAGS) -c main.cpp

.PHONY: clean

clean:
	rm -f *.o prg