#include "file_func.h"

int create_copy_file(int fd, char* name_copy_file)
{
    assert(name_copy_file);

    int fd_copy = -1;
    
    if((fd_copy = creat(name_copy_file, S_IRWXU)) == -1)
    {
        perror("Ошибка при создании файла");
        return -1;
    }

    if((fd_copy = open(name_copy_file, O_WRONLY)) == -1)
    {
        perror("Ошибка открытия файла");
        return -1;
    }
    
    long long size_fd = size_file(fd);
    char buffer_fd[BUFFER_SIZE] = "";

    ssize_t num_byte_read = read(fd, buffer_fd, size_fd);
    if(num_byte_read == -1)
    {
        perror("Ошибка чтения файла");
        return -1;
    }

    ssize_t num_byte_write = write(fd_copy, buffer_fd, size_fd);
    if(num_byte_write == -1)
    {
        perror("Ошибка записи в файл");
        return -1;
    }

    if(close(fd_copy) == -1)
    {
        perror("Ошибка при закрытии файла");
        return -1;
    }

    return 0;
}

int print_file(char* name_file)
{
    assert(name_file);

    int fd = open(name_file, O_RDONLY);
    if(fd == -1)
    {
        perror("Ошибка открытия файла");
        return -1;
    }

    long long size_fd = size_file(fd);
    char buffer_fd[BUFFER_SIZE] = "";

    ssize_t num_byte_read = read(fd, buffer_fd, size_fd);
    if(num_byte_read == -1)
    {
        perror("Ошибка чтения файла");
        return -1;
    }

    printf("%s", buffer_fd);

    if(close(fd) == -1)
    {
        perror("Ошибка при закрытии файла");
        return -1;
    }

    return 0;
}

long long size_file(int fd)
{
    struct stat info_file = {};

    if (fstat(fd, &info_file) == -1) 
    {
        perror("Ошибка \"fstat\"");
		return -1;
	}
	else
    {
		return info_file.st_size;
	}
}