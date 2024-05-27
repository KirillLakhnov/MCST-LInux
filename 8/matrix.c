#include "matrix.h"

volatile sig_atomic_t inters = 0;

int cur_row = -1;
int cur_col = -1;

void sign_handl(int sign)
{
    if(inters < 1)
    {
        if (cur_row != -1 && cur_col != -1)
        {
            printf("Текущая строка: %d, столбец: %d\n", cur_row, cur_col);
            signal(SIGINT, SIG_DFL);
        }
    }
    else
    {
        exit(0);
    }

    inters++;
}

void mul_matrix(int** first_matrix, int** second_matrix, int** result_matrix)
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            cur_row = i;
            cur_col = j;

            int sum = 0;
            for (int k = 0; k < MATRIX_SIZE; k++)
            {
                sum += first_matrix[i][k] * second_matrix[k][j];
            }
            result_matrix[i][j] = sum;

            sleep(1);
        }   
    }
}

