#ifndef __TP2_UTILS__
#define __TP2_UTILS__

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int64_t utils_random_number(int64_t min, int64_t max);

void utils_swap_int64_t(int64_t* a, int64_t* b);

char* utils_boolean_to_string(bool boolean);

#endif
