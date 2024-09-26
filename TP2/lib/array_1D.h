#ifndef __TP2_ARRAY_1D__
#define __TP2_ARRAY_1D__

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void array_1D_print(int64_t *array, size_t size);

void array_1D_random_fill_int(int64_t *array, size_t array_size, int64_t minimum_value, int64_t maximum_value);

int64_t array_1D_max(int64_t *array, size_t array_size);

uint64_t array_1D_occurrences_count(int64_t *array, size_t array_size, int64_t element);

int64_t array_1D_find_first(int64_t *array, size_t array_size, int64_t element);

int64_t array_1D_find_last(int64_t *array, size_t array_size, int64_t element);

void array_1D_reverse(int64_t *array, size_t array_size);

bool array_1D_is_palindrome(int64_t *array, size_t array_size);

// [1, 2, 3, 4, 5] => [5, 1, 2, 3, 4]
void array1D_rotate_right(int64_t *array, size_t array_size);

// [1, 2, 3, 4, 5] => [2, 3, 4, 5, 1]
void array1D_rotate_left(int64_t *array, size_t array_size);

#endif
