#ifndef __TP3_UTILS__
#define __TP3_UTILS__

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void utils_main_experimentation();

void utils_main_function_mutiple_results();

void utils_double_min_max_average(double *array, size_t array_size, double *min, double *max, double *average);

char *utils_boolean_to_string(bool boolean);

#endif
