#include "file_func.h"

int main(int argc, char *argv[])
{
    if(argc <= 1)
    {
        printf("\e[31mНе передано имя файла\e[0m");
        return NO_ARG;
    }

    int fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        perror("Ошибка открытия файла");
        return ERR_OPEN;
    }

    pid_t child_pid = fork();

    if(child_pid < 0)
    {
        perror("Ошибка \"fork\"");
        return ERR_FORK;
    }
    else if (child_pid == 0) //Порожденный процесс
    { 
        char child_copy_file_name[] = "child_copy_file.txt";
        if((create_copy_file(fd, child_copy_file_name)) == -1)
        {
            return ERR_CREAT_COPY;
        }

        printf("Содержимое файла, созданного в дочернем процессе:\n\n");
        if((print_file(child_copy_file_name)) == -1)
        {
            return ERR_PRINT;
        }
        printf("\n\n");
    }
    else //Родительский процесс
    {        
        waitpid(child_pid, NULL, 0); // Ждем пока завершится дочерный процесс

        lseek(fd, 0, SEEK_SET);

        char parent_copy_file_name[] = "parent_copy_file.txt";
        if((create_copy_file(fd, parent_copy_file_name)) == -1)
        {
            return ERR_CREAT_COPY;
        }

        printf("Содержимое файла, созданного в родительского процессе:\n\n");
        if((print_file(parent_copy_file_name)) == -1)
        {
            return ERR_PRINT;
        }
        printf("\n");
    }

    if(close(fd) == -1)
    {
        perror("Ошибка при закрытии файла");
        return ERR_CLOSE;
    }

    return 0;
}