#include "array_1D.h"

void array_1D_print(int64_t *array, size_t array_size) {
  printf("[");
  for (size_t index = 0; index < array_size; index++) {
    int64_t element = array[index];
    printf("%ld", element);
    bool is_last = index == array_size - 1;
    if (!is_last) {
      printf(", ");
    }
  }
  printf("]\n");
}

void array_1D_random_fill_int(int64_t *array, size_t array_size, int64_t minimum_value, int64_t maximum_value) {
  for (size_t index = 0; index < array_size; index++) {
    array[index] = utils_random_number(minimum_value, maximum_value);
  }
}

int64_t array_1D_max(int64_t *array, size_t array_size) {
  int64_t max = 0;
  if (array_size <= 0) {
    return max;
  }
  max = array[0];
  for (size_t index = 1; index < array_size; index++) {
    int64_t element = array[index];
    if (element > max) {
      max = element;
    }
  }
  return max;
}

uint64_t array_1D_occurrences_count(int64_t *array, size_t array_size, int64_t element) {
  uint64_t count = 0;
  for (size_t index = 0; index < array_size; index++) {
    if (array[index] == element) {
      count += 1;
    }
  }
  return count;
}

int64_t array_1D_find_first(int64_t *array, size_t array_size, int64_t element) {
  int64_t index_first = -1;
  for (size_t index = 0; index < array_size && index_first == -1; index++) {
    if (array[index] == element) {
      index_first = index;
    }
  }
  return index_first;
}

int64_t array_1D_find_last(int64_t *array, size_t array_size, int64_t element) {
  int64_t index_last = -1;
  for (size_t index = array_size - 1; index != 0 && index_last == -1; index--) {
    if (array[index] == element) {
      index_last = index;
    }
  }
  return index_last;
}

void array_1D_reverse(int64_t *array, size_t array_size) {
  size_t array_size_half = array_size / 2;
  for (size_t index = 0; index < array_size_half; index++) {
    size_t reverse_index = array_size - index - 1;
    utils_swap_int64_t(&array[index], &array[reverse_index]);
  }
}

bool array_1D_is_palindrome(int64_t *array, size_t array_size) {
  bool is_palindrome = true;
  size_t array_size_half = array_size / 2;
  for (size_t index = 0; index < array_size_half && is_palindrome; index++) {
    size_t reverse_index = array_size - index - 1;
    is_palindrome = array[index] == array[reverse_index];
  }
  return is_palindrome;
}

void array1D_rotate_right(int64_t *array, size_t array_size) {
  if (array_size <= 0) {
    return;
  }
  int64_t last_element = array[0];
  array[0] = array[array_size - 1];
  for (size_t index = 1; index < array_size; index++) {
    int64_t element = array[index];
    array[index] = last_element;
    last_element = element;
  }
}

void array1D_rotate_left(int64_t *array, size_t array_size) {
  if (array_size <= 0) {
    return;
  }
  int64_t last_element = array[array_size - 1];
  array[array_size - 1] = array[0];
  for (size_t index = array_size - 2; index < array_size; index--) {
    int64_t element = array[index];
    array[index] = last_element;
    last_element = element;
  }
}

void array1D_random_fill_double(double *array, size_t array_size, double minimum_value, double maximum_value) {
  for (size_t index = 0; index < array_size; index++) {
    array[index] = utils_random_double(minimum_value, maximum_value);
  }
}

void array_1D_print_double(double *array, size_t array_size) {
  printf("[");
  for (size_t index = 0; index < array_size; index++) {
    double element = array[index];
    printf("%f", element);
    bool is_last = index == array_size - 1;
    if (!is_last) {
      printf(", ");
    }
  }
  printf("]\n");
}

void array_1D_negative_positive(double *array, size_t array_size) {
  size_t negative_index = 0;
  size_t positive_index = array_size - 1;
  while (negative_index < positive_index) {
    if (array[negative_index] < 0) {
      negative_index += 1;
    } else {
      utils_swap_double(&array[negative_index], &array[positive_index]);
      positive_index -= 1;
    }
  }
}
