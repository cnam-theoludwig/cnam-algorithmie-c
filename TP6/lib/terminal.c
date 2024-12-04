#include "terminal.h"

void terminal_print_int(void* value) {
  printf("%d", *(int*)value);
}

void terminal_print_bool(void* value) {
  printf("%s", *(bool*)value ? "true" : "false");
}

void terminal_print_long(void* value) {
  printf("%ld", *(long*)value);
}

void terminal_print_unsigned_long(void* value) {
  printf("%lu", *(unsigned long*)value);
}

void terminal_print_float(void* value) {
  printf("%f", *(float*)value);
}

void terminal_print_double(void* value) {
  printf("%f", *(double*)value);
}

void terminal_print_int8_t(void* value) {
  printf("%d", *(int8_t*)value);
}

void terminal_print_int16_t(void* value) {
  printf("%d", *(int16_t*)value);
}

void terminal_print_int32_t(void* value) {
  printf("%d", *(int32_t*)value);
}

void terminal_print_int64_t(void* value) {
  printf("%ld", *(int64_t*)value);
}

void terminal_print_uint8_t(void* value) {
  printf("%u", *(uint8_t*)value);
}

void terminal_print_uint16_t(void* value) {
  printf("%u", *(uint16_t*)value);
}

void terminal_print_uint32_t(void* value) {
  printf("%u", *(uint32_t*)value);
}

void terminal_print_uint64_t(void* value) {
  printf("%lu", *(uint64_t*)value);
}

void terminal_print_char(void* value) {
  printf("%c", *(string_t)value);
}

void terminal_print_array(void* array, size_t array_size, size_t element_size, void (*print_element)(void*)) {
  printf("[");
  for (size_t index = 0; index < array_size; index++) {
    void* element = (string_t)array + index * element_size;
    print_element(element);
    bool is_last = index == array_size - 1;
    if (!is_last) {
      printf(", ");
    }
  }
  printf("]\n");
}

void terminal_print_string(void* value) {
  printf("%s", (string_t)value);
}

void terminal_print_linked_list(struct linked_list* linked_list, void (*print_element)(void*)) {
  if (linked_list == NULL) {
    errno = EINVAL;
    perror("Error (terminal_print_linked_list)");
    exit(EXIT_FAILURE);
  }
  struct linked_list_node* node_current = linked_list->head;
  while (node_current != NULL) {
    void* element = (string_t)node_current->data;
    node_current = node_current->next;
    print_element(element);
    printf(" -> ");
  }
  printf("NULL\n");
}
