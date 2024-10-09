#include "array_2D.h"

int64_t** array_2D_initialization(size_t rows, size_t columns) {
  int64_t** array = malloc(rows * sizeof(int64_t*));
  for (size_t row = 0; row < rows; row++) {
    array[row] = malloc(columns * sizeof(int64_t));
  }
  return array;
}

void array_2D_print(int64_t** array, size_t rows, size_t columns) {
  printf("[\n");
  for (size_t row = 0; row < rows; row++) {
    printf("  [");
    for (size_t column = 0; column < columns; column++) {
      int64_t element = array[row][column];
      printf("%ld", element);
      bool is_last = column == columns - 1;
      if (!is_last) {
        printf(", ");
      }
    }
    printf("]\n");
  }
  printf("]\n");
}

void array_2D_fill_random_int(int64_t** array, size_t rows, size_t columns, int64_t minimum_value, int64_t maximum_value) {
  for (size_t row = 0; row < rows; row++) {
    for (size_t column = 0; column < columns; column++) {
      array[row][column] = utils_random_number(minimum_value, maximum_value);
    }
  }
}

bool array_2D_get_is_sudoku(int64_t** array, size_t rows, size_t columns) {
  if (rows != 3 || columns != 3) {
    return false;
  }
  size_t size = rows * columns;
  for (size_t index = 0; index < size; index++) {
    int64_t element = array[index / columns][index % columns];

    for (size_t i = 0; i < index; i++) {
      if (array[i / columns][i % columns] == element) {
        return false;
      }
    }
  }
  return true;
}

void array_2D_free(int64_t** array, size_t rows) {
  for (size_t row = 0; row < rows; row++) {
    free(array[row]);
  }
  free(array);
}

int64_t** array_2D_matrix_sum(int64_t** matrix_a, int64_t** matrix_b, size_t rows, size_t columns) {
  int64_t** matrix_sum = array_2D_initialization(rows, columns);
  for (size_t row = 0; row < rows; row++) {
    for (size_t column = 0; column < columns; column++) {
      matrix_sum[row][column] = matrix_a[row][column] + matrix_b[row][column];
    }
  }
  return matrix_sum;
}

int64_t** array_2D_matrix_product(int64_t** matrix_a, int64_t** matrix_b, size_t rows_a, size_t columns_a, size_t columns_b) {
  int64_t** matrix_product = array_2D_initialization(rows_a, columns_b);
  for (size_t row = 0; row < rows_a; row++) {
    for (size_t column = 0; column < columns_b; column++) {
      int64_t sum = 0;
      for (size_t i = 0; i < columns_a; i++) {
        sum += matrix_a[row][i] * matrix_b[i][column];
      }
      matrix_product[row][column] = sum;
    }
  }
  return matrix_product;
}

int64_t** array_2D_matrix_identity(size_t size) {
  int64_t** matrix_identity = array_2D_initialization(size, size);
  for (size_t row = 0; row < size; row++) {
    for (size_t column = 0; column < size; column++) {
      matrix_identity[row][column] = row == column ? 1 : 0;
    }
  }
  return matrix_identity;
}
