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
  printf("------ Tableaux 1D ------\n\n");

  printf("------ Drapeau Hollandais ------\n");
  size_t size = 30;
  char* flag = dutch_flag_generate_random(size);
  dutch_flag_print(flag, size);

  dutch_flag_solution_optimized(flag, size);
  dutch_flag_print(flag, size);

  free(flag);
  printf("------ Drapeau Hollandais ------\n\n");

  printf("------ Variante à 2 ensembles de réels (tri négatif->positif) ------\n\n");
  size_t size_real = 10;
  double* real_numbers = malloc(size_real * sizeof(double));
  array1D_random_fill_double(real_numbers, size_real, -1.0, 1.0);
  array_1D_print_double(real_numbers, size_real);

  array_1D_negative_positive(real_numbers, size_real);
  array_1D_print_double(real_numbers, size_real);

  free(real_numbers);
  printf("------ Variante à 2 ensembles de réels (tri négatif->positif) ------\n\n");

  printf("------ Tableaux 2D ------\n");
  size_t rows = 3;
  size_t columns = 3;
  int64_t** sudoku = array_2D_initialization(rows, columns);
  array_2D_fill_random_int(sudoku, rows, columns, 1, 9);
  array_2D_print(sudoku, rows, columns);
  printf("array_2D_get_is_sudoku = %s\n\n", utils_boolean_to_string(array_2D_get_is_sudoku(sudoku, rows, columns)));
  array_2D_free(sudoku, rows);

  int64_t** sudoku_test = array_2D_initialization(rows, columns);
  sudoku_test[0][0] = 1;
  sudoku_test[0][1] = 2;
  sudoku_test[0][2] = 3;
  sudoku_test[1][0] = 4;
  sudoku_test[1][1] = 5;
  sudoku_test[1][2] = 6;
  sudoku_test[2][0] = 7;
  sudoku_test[2][1] = 8;
  sudoku_test[2][2] = 9;
  array_2D_print(sudoku_test, rows, columns);
  printf("array_2D_get_is_sudoku = %s\n", utils_boolean_to_string(array_2D_get_is_sudoku(sudoku_test, rows, columns)));
  array_2D_free(sudoku_test, rows);
  printf("------ Tableaux 2D ------\n\n");

  printf("------ Matrix ------\n");
  size_t rows_matrix = 3;
  size_t columns_matrix = 3;

  int64_t** matrix_identity = array_2D_matrix_identity(rows_matrix);
  printf("Matrix Identity\n");
  array_2D_print(matrix_identity, rows_matrix, columns_matrix);
  printf("Matrix Identity\n\n");

  int64_t** matrix_a = array_2D_initialization(rows_matrix, columns_matrix);
  array_2D_fill_random_int(matrix_a, rows_matrix, columns_matrix, 1, 9);
  printf("Matrix A\n");
  array_2D_print(matrix_a, rows_matrix, columns_matrix);
  printf("Matrix A\n\n");

  int64_t** matrix_b = array_2D_initialization(rows_matrix, columns_matrix);
  array_2D_fill_random_int(matrix_b, rows_matrix, columns_matrix, 1, 9);
  printf("Matrix B\n");
  array_2D_print(matrix_b, rows_matrix, columns_matrix);
  printf("Matrix B\n\n");

  int64_t** matrix_sum = array_2D_matrix_sum(matrix_a, matrix_b, rows_matrix, columns_matrix);
  printf("Matrix Sum, A + B\n");
  array_2D_print(matrix_sum, rows_matrix, columns_matrix);
  printf("Matrix Sum, A + B\n\n");

  int64_t** matrix_product = array_2D_matrix_product(matrix_a, matrix_b, rows_matrix, columns_matrix, columns_matrix);
  printf("Matrix Product, A * B\n");
  array_2D_print(matrix_product, rows_matrix, columns_matrix);
  printf("Matrix Product, A * B\n");

  array_2D_free(matrix_identity, rows_matrix);
  array_2D_free(matrix_a, rows_matrix);
  array_2D_free(matrix_b, rows_matrix);
  array_2D_free(matrix_sum, rows_matrix);
  array_2D_free(matrix_product, rows_matrix);
  printf("------ Matrix ------\n");

  return EXIT_SUCCESS;
}
