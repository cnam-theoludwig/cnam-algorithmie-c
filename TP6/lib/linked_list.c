#include "linked_list.h"

struct linked_list *linked_list_initialization() {
  struct linked_list *list = malloc(sizeof(struct linked_list));
  if (list == NULL) {
    perror("Error (linked_list_initialization)");
    exit(EXIT_FAILURE);
  }
  list->head = NULL;
  list->length = 0;
  return list;
}

struct linked_list_node *linked_list_add_in_head(struct linked_list *list, void *new_data) {
  if (list == NULL) {
    errno = EINVAL;
    perror("Error (linked_list_add_in_head)");
    exit(EXIT_FAILURE);
  }
  struct linked_list_node *node_new = malloc(sizeof(struct linked_list_node));
  if (node_new == NULL) {
    perror("Error (linked_list_add_in_head)");
    exit(EXIT_FAILURE);
  }
  node_new->data = new_data;
  node_new->next = list->head;
  list->head = node_new;
  list->length = list->length + 1;
  return node_new;
}

void linked_list_add_int_in_head(struct linked_list *list, int value) {
  int *new_value = malloc(sizeof(int));
  if (!new_value) {
    perror("Error (linked_list_add_int_in_head)");
    exit(EXIT_FAILURE);
  }
  *new_value = value;
  linked_list_add_in_head(list, new_value);
}

void linked_list_delete_in_head(struct linked_list *list) {
  if (list == NULL) {
    errno = EINVAL;
    perror("Error (linked_list_delete_in_head)");
    exit(EXIT_FAILURE);
  }
  if (list->head != NULL) {
    struct linked_list_node *node_to_remove = list->head;
    list->head = list->head->next;
    list->length = list->length - 1;
    free(node_to_remove);
  }
}

struct linked_list_node *linked_list_add_after_last(struct linked_list *list, void *new_data) {
  if (list == NULL) {
    errno = EINVAL;
    perror("Error (linked_list_add_after_last)");
    exit(EXIT_FAILURE);
  }
  if (list->head == NULL) {
    return linked_list_add_in_head(list, new_data);
  }
  struct linked_list_node *node_new = malloc(sizeof(struct linked_list_node));
  if (node_new == NULL) {
    perror("Error (linked_list_add_after_last)");
    exit(EXIT_FAILURE);
  }
  node_new->data = new_data;
  node_new->next = NULL;
  struct linked_list_node *node_current_last = list->head;
  size_t index = 0;
  while (index < list->length - 1) {
    node_current_last = node_current_last->next;
    index++;
  }
  node_current_last->next = node_new;
  list->length = list->length + 1;
  return node_new;
}

struct linked_list_node *linked_list_add_int_after_last(struct linked_list *list, int value) {
  int *new_value = malloc(sizeof(int));
  if (!new_value) {
    perror("Error (linked_list_add_int_after_last)");
    exit(EXIT_FAILURE);
  }
  *new_value = value;
  return linked_list_add_after_last(list, new_value);
}

void linked_list_free(struct linked_list *list) {
  struct linked_list_node *node_current = list->head;
  while (node_current != NULL) {
    struct linked_list_node *node_to_remove = node_current;
    node_current = node_current->next;
    free(node_to_remove);
  }
  list->head = NULL;
  free(list);
}

void linked_list_apply(struct linked_list *list, void (*apply_function)(void *)) {
  struct linked_list_node *node_current = list->head;
  while (node_current != NULL) {
    apply_function(node_current->data);
    node_current = node_current->next;
  }
}
