#include "parser.h"

const char OPTIONS[4] = {'m', 'c', 's', 't'};
const char* ELBRUS_OPTION[6] = {"1c+", "2c+", "2c3", "4c", "8c", "16c"};

void parser(int argc, char* argv[])
{
    struct ParserResult parser_result = {};

    parser_result.current_options = 0;
    parser_result.current_elbrus_options = 0;
    parser_result.current_non_options = 0;

    parser_result.current_incorrect_options = 0;
    parser_result.current_incorrect_elbrus_options = 0;

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            if (argv[i][1] == '-')
            {
                if (is_elbrus_option(argv[i] + 2))
                {
                    parser_result.elbrus_options[parser_result.current_elbrus_options] = argv[i] + 2;
                    parser_result.current_elbrus_options++;
                }
                else
                {
                    parser_result.incorrect_elbrus_option[parser_result.current_incorrect_elbrus_options] = argv[i] + 2;
                    parser_result.current_incorrect_elbrus_options++;
                }
            }
            else
            {
                int j = 1;
                while (argv[i][j] != '\0')
                {
                    if (is_option(argv[i][j]))
                    {
                        parser_result.options[parser_result.current_options] = argv[i][j];
                        parser_result.current_options++;
                    }
                    else
                    {
                        parser_result.incorrect_option[parser_result.current_incorrect_options] = argv[i][j];
                        parser_result.current_incorrect_options++;
                    }

                    j++;
                }
            }
        }
        else
        {
            parser_result.non_options[parser_result.current_non_options] = argv[i];
            parser_result.current_non_options++;
        }
    }

    print_parser_result(parser_result);
}

void print_parser_result(struct ParserResult parser_result)
{
    if((parser_result.current_incorrect_options == 0) &&  
       (parser_result.current_incorrect_elbrus_options == 0))
    {
        printf("Options are correct: ");

        for (int i = 0; i < parser_result.current_options; i++)
        {
            printf("%c", parser_result.options[i]);

            if ((parser_result.current_elbrus_options == 0) &&
                (parser_result.current_non_options == 0))
            {
                PRINT_COMMA_OR_DOT(parser_result.current_options);
            }
            else
            {
                printf(", ");
            }
        }
        for (int i = 0; i < parser_result.current_elbrus_options; i++)
        {
            printf("%s", parser_result.elbrus_options[i]);

            if (parser_result.current_non_options == 0)
            {
                PRINT_COMMA_OR_DOT(parser_result.current_elbrus_options);
            }
            else
            {
                printf(", ");
            }
        }

        if(parser_result.current_non_options > 0)
        {
            printf("non-options: ");

            for (int i = 0; i < parser_result.current_non_options; i++)
            {
                printf("%s", parser_result.non_options[i]);

                PRINT_COMMA_OR_DOT(parser_result.current_non_options);
            }
        }
    }
    else
    {
        printf("\e[31mOptions are incorrect:\e[0m ");

        for (int i = 0; i < parser_result.current_incorrect_options; i++)
        {
            printf("%c", parser_result.incorrect_option[i]);

            if (parser_result.current_incorrect_elbrus_options == 0)
            {
                PRINT_COMMA_OR_DOT(parser_result.current_incorrect_options);
            }
            else
            {
                printf(", ");
            }
        }
        for (int i = 0; i < parser_result.current_incorrect_elbrus_options; i++)
        {
            printf("%s", parser_result.incorrect_elbrus_option[i]);

            PRINT_COMMA_OR_DOT(parser_result.current_incorrect_elbrus_options);
        }
    }
}

//=======================================

int is_option(char symbol)
{
    if(symbol == OPTIONS[0]) return 1;
    if(symbol == OPTIONS[1]) return 1;
    if(symbol == OPTIONS[2]) return 1;
    if(symbol == OPTIONS[3]) return 1;

    return 0;
}

int is_elbrus_option(char* string)
{
    assert(string);

    if(strncmp(string, "elbrus=", 7) == 0)
    {
        if(strncmp(ELBRUS_OPTION[0], string + 7, 3) == 0) return 1;
        if(strncmp(ELBRUS_OPTION[1], string + 7, 3) == 0) return 1;
        if(strncmp(ELBRUS_OPTION[2], string + 7, 3) == 0) return 1;
        if(strncmp(ELBRUS_OPTION[3], string + 7, 2) == 0) return 1;
        if(strncmp(ELBRUS_OPTION[4], string + 7, 2) == 0) return 1;
        if(strncmp(ELBRUS_OPTION[5], string + 7, 3) == 0) return 1;

        return 0;
    }

    return 0;
}