#include "sort.h"

int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("\e[31mПередано не достаточно аргументов:\e[0m\n"
               "\tвходной файл, выходной файл,\n"
               "\tспособ сортировки (alphabet, length)\n");
        return 1;
    }

    sort_file(argv[1], argv[2], argv[3]);

    return 0;
}