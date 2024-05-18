#include "background_info_file.h"

void get_background_info_file(char* name_file)
{
    assert(name_file);

    struct stat info_file = {};

    if(stat(name_file, &info_file) == -1)
    {
        perror("Ошибка в \"stat\"");
    }

    printf("Информация о файле \"%s\":\n", name_file);

    get_type_file(info_file);

    printf("\tID устройства с файлом: %d\n", info_file.st_dev);
    printf("\tНомер inode: %llu\n\n", info_file.st_ino);

    printf("\tРазмер файла: %lld байт\n", (long long)info_file.st_size);
    printf("\tРазмер блока ввода-вывода в файловой системе: %lld байт\n", (long long)info_file.st_blksize);
    printf("\tКоличество выделенных блоков по 512 байт: %d байт\n\n", info_file.st_rdev);

    printf("\tКоличество жёстких ссылок: %d\n\n", info_file.st_nlink);

    printf("\tID пользователя-владельца: %d\n", info_file.st_uid);
    printf("\tID группы-владельца: %d\n", info_file.st_gid);
    printf("\tID устройства: %d\n\n", info_file.st_rdev);

    char last_access_time[MAX_LEN_STRING_TIME] = "";
    long_in_time(info_file, last_access_time);

    char last_change_time[MAX_LEN_STRING_TIME] = "";
    long_in_time(info_file, last_change_time);

    char last_state_change_time[MAX_LEN_STRING_TIME] = "";
    long_in_time(info_file, last_state_change_time);

    printf("\tВремя последнего доступа: %s\n", last_access_time);
    printf("\tВремя последнего изменения: %s\n", last_change_time);
    printf("\tВремя последней смены состояния: %s\n\n", last_state_change_time);
}

void get_type_file(struct stat info_file)
{
    printf("\tТип файла: ");
    if(S_ISLNK (info_file.st_mode)) {printf("символьная ссылка\n\n");     return;}
    if(S_ISREG (info_file.st_mode)) {printf("обычный файл\n\n");          return;}
    if(S_ISDIR (info_file.st_mode)) {printf("каталог\n\n");               return;}
    if(S_ISCHR (info_file.st_mode)) {printf("символьное устройство\n\n"); return;}
    if(S_ISBLK (info_file.st_mode)) {printf("блочное устройство\n\n");    return;}
    if(S_ISFIFO(info_file.st_mode)) {printf("канал FIFO\n\n");            return;}
    if(S_ISSOCK(info_file.st_mode)) {printf("сокет\n\n");                 return;}

    printf("неизвестно\n\n");
}

void long_in_time(struct stat info_file, char* string_time)
{
    assert(string_time);
    
    const time_t time_t = time(&info_file.st_atime);
    struct tm* time_tm = localtime(&time_t);
    strftime(string_time, MAX_LEN_STRING_TIME, "%d.%m.%Y %H:%M:%S", time_tm);
}