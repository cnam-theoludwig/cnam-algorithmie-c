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

string_t string_copy(const string_t string);

string_t string_reverse(const string_t string);

string_t string_substring(const string_t string, size_t index_start, size_t index_end);

size_t string_split(const string_t string, char separator, string_t** result);

string_t* string_split_return_result(const string_t string, char separator, size_t* result_size);

char convert_digit_to_character(const char digit);

string_t convert_character_to_string(const char character);

uint64_t mathematics_absolute_value(const int64_t number);

string_t string_int_to_string(int integer);

#endif
