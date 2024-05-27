#include "sort.h"

void sort_file(char* input_file, char* output_file, char* sorting_method) 
{
    FILE* input_file_d = fopen(input_file, "r");
    if (input_file_d == NULL) 
    {
        perror("Ошибка открытия входного файла");
        return;
    }

    FILE* output_file_d = fopen(output_file, "w");
    if (output_file_d == NULL) 
    {
        perror("Ошибка открытия выходного файла");

        FLOSE(input_file_d, "Ошибка закрытия входного файла");

        return;
    }

    char buffer[MAX_LENGTH];
    char** lines = (char**)calloc(MAX_LENGTH, sizeof(char*));
    if (lines == NULL) 
    {
        perror("Ошибка выделения памяти");

        FLOSE(input_file_d, "Ошибка закрытия входного файла");
        FLOSE(output_file_d, "Ошибка закрытия выходного файла");

        return;
    }

    int num_lines = 0;

    while (fgets(buffer, MAX_LENGTH, input_file_d) != NULL) 
    {
        if (strcspn(buffer, "\n\t ") != strlen(buffer)) 
        {
            lines[num_lines] = (char*)calloc(strlen(buffer) + 1, sizeof(char));
            if (lines[num_lines] == NULL) 
            {
                perror("Ошибка выделения памяти");

                FLOSE(input_file_d, "Ошибка закрытия входного файла");
                FLOSE(output_file_d, "Ошибка закрытия выходного файла");

                free(lines);

                return;
            }
            strcpy(lines[num_lines], buffer);
            num_lines++;
        }
    }

    if (strcmp(sorting_method, "length") == 0) 
    {
        qsort(lines, num_lines, sizeof(char*), compare_length);
    } 
    else if (strcmp(sorting_method, "alphabet") == 0) 
    {
        qsort(lines, num_lines, sizeof(char*), compare);
    } 
    else 
    {
        printf("Неверный метод сортировки. Пожалуйста, используйте «length» или «alphabet».\n");

        free(lines);

        FLOSE(input_file_d, "Ошибка закрытия входного файла");
        FLOSE(output_file_d, "Ошибка закрытия выходного файла");

        return;
    }

    for (int i = 0; i < num_lines; i++) 
    {
        fprintf(output_file_d, "%s", lines[i]);
        printf("%s", lines[i]);
        free(lines[i]);
    }

    free(lines);

    FLOSE(input_file_d, "Ошибка закрытия входного файла");
    FLOSE(output_file_d, "Ошибка закрытия выходного файла");
}

int compare(const void *a, const void *b) 
{
    return stricmp(*(const char**)a, *(const char**)b);
}

int compare_length(const void *a, const void *b) 
{
    size_t len_a = strlen(*(const char**)a);
    size_t len_b = strlen(*(const char**)b);

    if (len_a < len_b) 
    {
        return -1;
    } 
    else if (len_a > len_b) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

int stricmp (const char* str1, const char* str2)
{
    assert (str1);
    assert (str2);
    
    int i = 0;
    while ((tolower(str1[i]) == tolower(str2[i])) && (str1[i] != '\0') && (str2[i++] != '\0'));

    return tolower(str1[i]) - tolower(str2[i]);
}