#ifndef __TP3_STRING__
#define __TP3_STRING__

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void string_main();

typedef char* string_t;

/**
 * @brief Return the length of a string (excluding '\0').
 *
 * @param string
 * @return size_t
 */
size_t string_get_length(const string_t string);

/**
 * @brief Check if two strings are equals.
 *
 * @param string1
 * @param string2
 * @return true if the strings are equals.
 * @return false if the strings are not equals.
 */
bool string_equals(const string_t string1, const string_t string2);

#endif
