#include "parser.h"

int main(int argc, char *argv[])
{
    if(argc <= 1)
    {
        printf("\e[31mНе переданы аргументы командной строки\e[0m");
    }

    parser(argc, argv);

    return 0;
}
