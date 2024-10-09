#ifndef __TP2_DUTCH_FLAG__
#define __TP2_DUTCH_FLAG__

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

char* dutch_flag_generate_random(size_t size);

void dutch_flag_print_color(char color);

void dutch_flag_print(char* flag, size_t size);

void dutch_flag_solution(char* flag, size_t size);

void dutch_flag_solution_optimized(char* flag, size_t size);

#endif
