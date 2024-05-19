#ifndef FILE_FUNC_H
#define FILE_FUNC_H

#include <stdio.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

enum ERRORS {
    NO_ARG         = 1,
    ERR_OPEN       = 2,
    ERR_CLOSE      = 3,
    ERR_FORK       = 4,
    ERR_CREAT_COPY = 5,
    ERR_READ       = 6,
    ERR_PRINT      = 7,
};

int create_copy_file(int fd, char* name_copy_file);

int print_file(char* name_file);

long long size_file(int fd);

#endif //FILE_FUNC_H