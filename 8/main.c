#include "matrix.h"

int main() 
{
    int** first_matrix  = (int**)calloc(MATRIX_SIZE, sizeof(int*));
    int** second_matrix = (int**)calloc(MATRIX_SIZE, sizeof(int*));
    int** result_matrix = (int**)calloc(MATRIX_SIZE, sizeof(int*));
    
    for (int i = 0; i < MATRIX_SIZE; i++) 
    {
        first_matrix[i]  = (int *)calloc(MATRIX_SIZE, sizeof(int));
        second_matrix[i] = (int *)calloc(MATRIX_SIZE, sizeof(int));
        result_matrix[i] = (int *)calloc(MATRIX_SIZE, sizeof(int));
        for (int j = 0; j < MATRIX_SIZE; j++) 
        {
            first_matrix[i][j]  = i % 25;
            second_matrix[i][j] = j % 5;
        }
    }

    signal(SIGINT, sign_handl);

    mul_matrix(first_matrix, second_matrix, result_matrix);

    for (int i = 0; i < MATRIX_SIZE; i++) 
    {
        free(first_matrix[i]);
        free(second_matrix[i]);
        free(result_matrix[i]);
    }
    free(first_matrix);
    free(second_matrix);
    free(result_matrix);

    return 0;
}