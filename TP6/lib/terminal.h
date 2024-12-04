#ifndef __TP6_TERMINAL__
#define __TP6_TERMINAL__

#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "linked_list_double.h"
#include "types.h"

/**
 * @brief Print a int.
 *
 * @param value
 */
void terminal_print_int(void* value);

/**
 * @brief Print a boolean.
 *
 * @param value
 */
void terminal_print_bool(void* value);

/**
 * @brief Print a long.
 *
 * @param value
 */
void terminal_print_long(void* value);

/**
 * @brief Print a unsigned long.
 *
 * @param value
 */
void terminal_print_unsigned_long(void* value);

/**
 * @brief Print a float.
 *
 * @param value
 */
void terminal_print_float(void* value);

/**
 * @brief Print a double.
 *
 * @param value
 */
void terminal_print_double(void* value);

/**
 * @brief Print a int8_t.
 *
 * @param value
 */
void terminal_print_int8_t(void* value);

/**
 * @brief Print a int16_t.
 *
 * @param value
 */
void terminal_print_int16_t(void* value);

/**
 * @brief Print a int32_t.
 *
 * @param value
 */
void terminal_print_int32_t(void* value);

/**
 * @brief Print a int64_t.
 *
 * @param value
 */
void terminal_print_int64_t(void* value);

/**
 * @brief Print a uint8_t.
 *
 * @param value
 */
void terminal_print_uint8_t(void* value);

/**
 * @brief Print a uint16_t.
 *
 * @param value
 */
void terminal_print_uint16_t(void* value);

/**
 * @brief Print a uint32_t.
 *
 * @param value
 */
void terminal_print_uint32_t(void* value);

/**
 * @brief Print a uint64_t.
 *
 * @param value
 */
void terminal_print_uint64_t(void* value);

/**
 * @brief Print a char.
 *
 * @param value
 */
void terminal_print_char(void* value);

/**
 * @brief Print a string.
 *
 * @param value
 */
void terminal_print_string(void* value);

/**
 * @brief Print a linked list.
 *
 * @param linked_list
 * @param print_element
 */
void terminal_print_linked_list(struct linked_list* linked_list, void (*print_element)(void*));

void terminal_print_linked_list_double(struct linked_list_double* list, void (*print_function)(void*));

#endif
