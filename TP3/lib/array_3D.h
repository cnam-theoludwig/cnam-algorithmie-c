#ifndef __TP3_ARRAY_3D__
#define __TP3_ARRAY_3D__

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "string.h"
#include "utils.h"

void array_3D_main();

int ***array_3D_init(size_t sizeI, size_t sizeJ, size_t sizeK);

int array_3D_get(int ***array, size_t i, size_t j, size_t k);

void array_3D_set(int ***array, size_t i, size_t j, size_t k, int element);

void array_3D_print(int ***array, size_t sizeI, size_t sizeJ, size_t sizeK);

#endif
