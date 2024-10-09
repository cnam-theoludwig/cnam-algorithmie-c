#include "utils.h"

void utils_main_experimentation() {
  printf("------ Arithmétique des pointeurs ------\n");
  int *pointer1 = NULL;
  printf("pointer1 = %p ; &pointer = %p\n", (void *)pointer1, (void *)&pointer1);

  int array[2] = {5, 8};

  int a = *array;
  int b = *array + 1;

  int *pointer = &a;
  printf("pointer = %p ; &pointer = %p ; *pointer = %d ; &a = %p\n", (void *)pointer, (void *)&pointer, *pointer, (void *)&a);

  pointer++;
  printf("pointer = %p ; &pointer = %p ; *pointer = %d ; &b = %p\n", (void *)pointer, (void *)&pointer, *pointer, (void *)&b);

  printf("------ Arithmétique des pointeurs ------\n");
}

void utils_main_function_mutiple_results() {
  printf("------ Fonction avec plusieurs résultats ------\n");
  size_t size = 5;
  double array[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
  double min = 0.0;
  double max = 0.0;
  double average = 0.0;
  utils_double_min_max_average(array, size, &min, &max, &average);
  printf("min = %f ; max = %f ; average = %f\n", min, max, average);
  printf("------ Fonction avec plusieurs résultats ------\n");
}

void utils_double_min_max_average(double *array, size_t array_size, double *min, double *max, double *average) {
  *average = 0.0;
  *min = 0.0;
  *max = 0.0;
  if (array_size <= 0) {
    return;
  }
  *min = array[0];
  *max = array[0];
  double sum = 0.0;
  for (size_t index = 0; index < array_size; index++) {
    double element = array[index];
    if (element < *min) {
      *min = element;
    }
    if (element > *max) {
      *max = element;
    }
    sum += element;
  }
  *average = sum / array_size;
}

char *utils_boolean_to_string(bool boolean) {
  return boolean ? "true" : "false";
}
