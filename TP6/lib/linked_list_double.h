#ifndef __TP6_LINKED_LIST_DOUBLE__
#define __TP6_LINKED_LIST_DOUBLE__

#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "types.h"

struct linked_list_double {
  struct linked_list_double_node *head;
  struct linked_list_double_node *tail;
  size_t length;
};

struct linked_list_double_node {
  void *data;
  struct linked_list_double_node *prev;
  struct linked_list_double_node *next;
};

struct linked_list_double *linked_list_double_initialization();

struct linked_list_double_node *linked_list_double_add_in_head(struct linked_list_double *list, void *new_value);

void linked_list_double_add_int_in_head(struct linked_list_double *list, int value);

void linked_list_double_delete_in_head(struct linked_list_double *list);

struct linked_list_double_node *linked_list_double_add_in_tail(struct linked_list_double *list, void *new_data);

void linked_list_double_add_int_in_tail(struct linked_list_double *list, int value);

void linked_list_double_free(struct linked_list_double *list);

void linked_list_double_apply(struct linked_list_double *list, void (*apply_function)(void *));

#endif
