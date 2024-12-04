#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tp6project.h"

void int_multiply_by_2(void *value) {
  int *value_int = (int *)value;
  *value_int = *value_int * 2;
}

int main() {
  printf("TP6\n");

  printf("---linked_list---\n");
  struct linked_list *list = linked_list_initialization();
  linked_list_add_int_after_last(list, 4);
  linked_list_add_int_after_last(list, 8);
  linked_list_add_int_after_last(list, 15);

  terminal_print_linked_list(list, terminal_print_int);
  linked_list_apply(list, int_multiply_by_2);
  terminal_print_linked_list(list, terminal_print_int);

  struct linked_list_node *current = list->head;
  while (current != NULL) {
    free(current->data);
    current = current->next;
  }
  linked_list_free(list);
  printf("---linked_list---\n\n");

  printf("---double_linked_list---\n");
  struct linked_list_double *list_double = linked_list_double_initialization();

  linked_list_double_add_int_in_tail(list_double, 4);
  linked_list_double_add_int_in_tail(list_double, 8);
  linked_list_double_add_int_in_tail(list_double, 15);

  printf("List after adding elements to the tail: ");
  terminal_print_linked_list_double(list_double, terminal_print_int);

  linked_list_double_apply(list_double, int_multiply_by_2);
  printf("List after multiplying each element by 2: ");
  terminal_print_linked_list_double(list_double, terminal_print_int);

  linked_list_double_add_int_in_head(list_double, 2);
  linked_list_double_add_int_in_head(list_double, 1);
  printf("List after adding elements to the head: ");
  terminal_print_linked_list_double(list_double, terminal_print_int);

  // linked_list_double_delete_in_head(list_double);
  // printf("List after deleting the head: ");
  // terminal_print_linked_list_double(list_double, terminal_print_int);

  struct linked_list_double_node *current_double = list_double->head;
  while (current_double != NULL) {
    free(current_double->data);
    current_double = current_double->next;
  }
  linked_list_double_free(list_double);

  printf("---double_linked_list---\n");
  return EXIT_SUCCESS;
}
