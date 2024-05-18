#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NUM_ARG 100

#define PRINT_COMMA_OR_DOT(MAX_NUMBER_OBJECTS)  if (i == MAX_NUMBER_OBJECTS - 1) \
                                                {\
                                                    printf(".\n");\
                                                }\
                                                else\
                                                {\
                                                    printf(", ");\
                                                }

struct ParserResult {
    char options[MAX_NUM_ARG];
    char* elbrus_options[MAX_NUM_ARG];
    char* non_options[MAX_NUM_ARG];

    size_t current_options;
    size_t current_elbrus_options;
    size_t current_non_options;

    char incorrect_option[MAX_NUM_ARG];
    char* incorrect_elbrus_option[MAX_NUM_ARG];

    size_t current_incorrect_options;
    size_t current_incorrect_elbrus_options;
};

void parser(int argc, char* argv[]);

void print_parser_result(struct ParserResult parser_result);

//=======================================
int is_option(char symbol);
int is_elbrus_option(char* string);


#endif //PARSER_H