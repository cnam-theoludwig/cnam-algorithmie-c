#include "linked_list_double.h"

struct linked_list_double *linked_list_double_initialization() {
  struct linked_list_double *list = malloc(sizeof(struct linked_list_double));
  if (list == NULL) {
    perror("Error (linked_list_double_initialization)");
    exit(EXIT_FAILURE);
  }
  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
  return list;
}

struct linked_list_double_node *linked_list_double_add_in_head(struct linked_list_double *list, void *new_data) {
  if (list == NULL) {
    errno = EINVAL;
    perror("Error (linked_list_double_add_in_head)");
    exit(EXIT_FAILURE);
  }
  struct linked_list_double_node *node_new = malloc(sizeof(struct linked_list_double_node));
  if (node_new == NULL) {
    perror("Error (linked_list_double_add_in_head)");
    exit(EXIT_FAILURE);
  }
  node_new->data = new_data;
  node_new->prev = NULL;
  node_new->next = list->head;

  if (list->head != NULL) {
    list->head->prev = node_new;
  } else {
    list->tail = node_new;
  }

  list->head = node_new;
  list->length++;
  return node_new;
}

void linked_list_double_add_int_in_head(struct linked_list_double *list, int value) {
  int *new_value = malloc(sizeof(int));
  if (!new_value) {
    perror("Error (linked_list_double_add_int_in_head)");
    exit(EXIT_FAILURE);
  }
  *new_value = value;
  linked_list_double_add_in_head(list, new_value);
}

void linked_list_double_delete_in_head(struct linked_list_double *list) {
  if (list == NULL) {
    errno = EINVAL;
    perror("Error (linked_list_double_delete_in_head)");
    exit(EXIT_FAILURE);
  }
  if (list->head != NULL) {
    struct linked_list_double_node *node_to_remove = list->head;
    list->head = list->head->next;

    if (list->head != NULL) {
      list->head->prev = NULL;
    } else {
      list->tail = NULL;
    }

    list->length--;
    free(node_to_remove);
  }
}

struct linked_list_double_node *linked_list_double_add_in_tail(struct linked_list_double *list, void *new_data) {
  if (list == NULL) {
    errno = EINVAL;
    perror("Error (linked_list_double_add_in_tail)");
    exit(EXIT_FAILURE);
  }
  struct linked_list_double_node *node_new = malloc(sizeof(struct linked_list_double_node));
  if (node_new == NULL) {
    perror("Error (linked_list_double_add_in_tail)");
    exit(EXIT_FAILURE);
  }
  node_new->data = new_data;
  node_new->next = NULL;
  node_new->prev = list->tail;

  if (list->tail != NULL) {
    list->tail->next = node_new;
  } else {
    list->head = node_new;
  }

  list->tail = node_new;
  list->length++;
  return node_new;
}

void linked_list_double_add_int_in_tail(struct linked_list_double *list, int value) {
  int *new_value = malloc(sizeof(int));
  if (!new_value) {
    perror("Error (linked_list_double_add_int_in_tail)");
    exit(EXIT_FAILURE);
  }
  *new_value = value;
  linked_list_double_add_in_tail(list, new_value);
}

void linked_list_double_free(struct linked_list_double *list) {
  if (list == NULL) {
    return;
  }
  struct linked_list_double_node *node_current = list->head;
  while (node_current != NULL) {
    struct linked_list_double_node *node_to_remove = node_current;
    node_current = node_current->next;
    free(node_to_remove);
  }
  free(list);
}

void linked_list_double_apply(struct linked_list_double *list, void (*apply_function)(void *)) {
  struct linked_list_double_node *node_current = list->head;
  while (node_current != NULL) {
    apply_function(node_current->data);
    node_current = node_current->next;
  }
}
