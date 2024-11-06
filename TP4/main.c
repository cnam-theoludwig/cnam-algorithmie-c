#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tp4project.h"

int main() {
  string_t string = "Hello, World!";
  string_t string_2 = string_copy(string);

  string_2[0] = 'a';
  printf("string: %s\n", string);
  printf("string_copy: %s\n", string_2);
  free(string_2);

  string_t string_reversed = string_reverse(string);
  printf("string_reversed: %s\n", string_reversed);
  free(string_reversed);

  string = "abcdef";
  string_t substring = string_substring(string, 1, 3);
  printf("string: %s, substring(1, 3): %s\n", string, substring);
  free(substring);

  string = "a,b,c";
  string_t* result = NULL;
  size_t result_size = string_split(string, ',', &result);
  printf("string_split(%s, ','):\n", string);
  for (size_t index = 0; index < result_size; index++) {
    printf("result[%zu]: %s\n", index, result[index]);
    free(result[index]);
  }
  free(result);

  int integer = 373;
  string_t string_int = string_int_to_string(integer);
  printf("string_int_to_string(%d): \"%s\"\n", integer, string_int);
  free(string_int);

  return EXIT_SUCCESS;
}
