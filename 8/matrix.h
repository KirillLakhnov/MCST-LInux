#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define MATRIX_SIZE 1000

void sign_handl(int sign);

void mul_matrix(int** first_matrix, int** second_matrix, int** result_matrix);

#endif //MATRIX_H