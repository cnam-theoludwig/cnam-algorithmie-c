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
  return EXIT_SUCCESS;
}
