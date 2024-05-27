CC = gcc
CFLAGS = 

all: first_user.c second_user.c
	$(CC) first_user.c $(CFLAGS) -o first_user
	$(CC) second_user.c $(CFLAGS) -o second_user

.PHONY: clean

clean:
	rm -f first_user second_user