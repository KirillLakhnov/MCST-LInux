#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "error_check.h"

int main()
{
    int file_descriptor = open("non_existent_file.txt", O_RDONLY); //Попытаемся открыть файл, которого не существует на чтение.

    if (file_descriptor == -1)
    {
        error_check();
    }

    if (close(file_descriptor) == -1)
    {
        perror("Ошибка при закрытии файла");
        return 1;
    }

    return 0;
}