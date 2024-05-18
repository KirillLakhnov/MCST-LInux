#ifndef BACKGROUND_INFO_FILE_H
#define BACKGROUND_INFO_FILE_H

#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>

#define MAX_LEN_STRING_TIME 40

void get_background_info_file(char* name_file);

void get_type_file(struct stat info_file);

void long_in_time(struct stat info_file, char* string_time);

#endif //BACKGROUND_INFO_FILE_H