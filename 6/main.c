#include "background_info_file.h"

int main(int argc, char *argv[])
{
    if(argc <= 1)
    {
        printf("\e[31mНе передано имя файла, информацию о котором надо получить\e[0m");
        return 1;
    }

    get_background_info_file(argv[1]);

    return 0;
}