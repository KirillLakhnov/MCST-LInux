#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MAX_LENGTH 1000

#define FLOSE(file, text)   if(fclose(file) != 0)    \
                            {                        \
                                perror(text);        \
                            }



void sort_file(char* input_file, char* output_file, char* sorting_method);

int compare(const void *a, const void *b) ;
int compare_length(const void *a, const void *b);

int stricmp (const char* str1, const char* str2);

#endif //SORT_H