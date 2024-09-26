#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tp2project.h"

int main() {
  srand(time(NULL));

  printf("------ Tableaux 1D ------\n");
  int64_t a = 10;
  int64_t b = 20;
  printf("a = %ld ; b = %ld\n", a, b);
  printf("swap(&a, &b)\n");
  utils_swap_int64_t(&a, &b);
  printf("a = %ld ; b = %ld\n\n", a, b);

  size_t array_size = 10;
  int64_t array[array_size];
  printf("array_1D_random_fill_int = ");
  array_1D_random_fill_int(array, array_size, -10, 10);
  array_1D_print(array, sizeof(array) / sizeof(int64_t));

  printf("array_1D_reverse = ");
  array_1D_reverse(array, array_size);
  array_1D_print(array, sizeof(array) / sizeof(int64_t));

  printf("array_1D_max = %ld\n", array_1D_max(array, array_size));
  printf("array_1D_occurrences_count = %lu\n", array_1D_occurrences_count(array, array_size, 10));
  printf("array_1D_find_first(5) = %ld\n", array_1D_find_first(array, array_size, 5));
  printf("array_1D_find_last(5) = %ld\n", array_1D_find_last(array, array_size, 5));
  printf("array_1D_is_palindrome = %s\n", utils_boolean_to_string(array_1D_is_palindrome(array, array_size)));

  printf("\n");
  int64_t array_test[] = {1, 2, 2, 1};
  size_t array_test_size = sizeof(array_test) / sizeof(int64_t);
  array_1D_print(array_test, array_test_size);
  printf("array_1D_is_palindrome = %s\n", utils_boolean_to_string(array_1D_is_palindrome(array_test, array_test_size)));
  printf("\n");

  int64_t array_test_rotate[] = {1, 2, 3, 4, 5};
  size_t array_test_rotate_size = sizeof(array_test_rotate) / sizeof(int64_t);
  array_1D_print(array_test_rotate, array_test_rotate_size);
  printf("array1D_rotate_right = ");
  array1D_rotate_right(array_test_rotate, array_test_rotate_size);
  array_1D_print(array_test_rotate, array_test_rotate_size);
  printf("\n");

  int64_t array_test_rotate_2[] = {1, 2, 3, 4, 5};
  size_t array_test_rotate_2_size = sizeof(array_test_rotate_2) / sizeof(int64_t);
  array_1D_print(array_test_rotate_2, array_test_rotate_2_size);
  printf("array1D_rotate_left = ");
  array1D_rotate_left(array_test_rotate_2, array_test_rotate_2_size);
  array_1D_print(array_test_rotate_2, array_test_rotate_2_size);
  printf("------ Tableaux 1D ------\n");

  return EXIT_SUCCESS;
}
