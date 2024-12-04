#ifndef __TP6_LINKED_LIST__
#define __TP6_LINKED_LIST__

#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "types.h"

struct linked_list {
  struct linked_list_node *head;
  size_t length;
};

struct linked_list_node {
  void *data;
  struct linked_list_node *next;
};

struct linked_list *linked_list_initialization();

/**
 * @brief Add a new node in the head of the linked list.
 *
 * @param list
 * @param new_value
 * @return struct linked_list_node*
 */
struct linked_list_node *linked_list_add_in_head(struct linked_list *list, void *new_value);

void linked_list_add_int_in_head(struct linked_list *list, int value);

/**
 * @brief Delete node in the head of the linked list.
 *
 * @param list
 */
void linked_list_delete_in_head(struct linked_list *list);

/**
 * @brief Add a new node in the tail of the linked list.
 *
 * @param list
 * @param new_data
 * @return struct linked_list_node*
 */
struct linked_list_node *linked_list_add_after_last(struct linked_list *list, void *new_data);

struct linked_list_node *linked_list_add_int_after_last(struct linked_list *list, int value);

/**
 * @brief Frees the linked list.
 *
 * @param list
 */
void linked_list_free(struct linked_list *list);

void linked_list_apply(struct linked_list *list, void (*apply_function)(void *));

#endif
