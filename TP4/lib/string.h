#ifndef __TP4_STRING__
#define __TP4_STRING__

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef char* string_t;

/**
 * @brief Return the length of a string (excluding '\0').
 *
 * @param string
 * @return size_t
 */
size_t string_get_length(const string_t string);

#endif
