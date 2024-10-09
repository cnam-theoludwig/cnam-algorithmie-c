#ifndef __TP2_ARRAY_2D__
#define __TP2_ARRAY_2D__

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int64_t** array_2D_initialization(size_t rows, size_t columns);

void array_2D_print(int64_t** array, size_t rows, size_t columns);

void array_2D_fill_random_int(int64_t** array, size_t rows, size_t columns, int64_t minimum_value, int64_t maximum_value);

bool array_2D_get_is_sudoku(int64_t** array, size_t rows, size_t columns);

void array_2D_free(int64_t** array, size_t rows);

int64_t** array_2D_matrix_sum(int64_t** matrix_a, int64_t** matrix_b, size_t rows, size_t columns);

int64_t** array_2D_matrix_product(int64_t** matrix_a, int64_t** matrix_b, size_t rows_a, size_t columns_a, size_t columns_b);

int64_t** array_2D_matrix_identity(size_t size);

#endif
