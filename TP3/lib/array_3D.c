#include "array_3D.h"

void array_3D_main() {
  printf("------ Tableau 3D ------\n");
  size_t sizeI = 10;
  size_t sizeJ = 10;
  size_t sizeK = 10;

  int ***array = array_3D_init(sizeI, sizeJ, sizeK);
  array_3D_print(array, sizeI, sizeJ, sizeK);

  printf("------ Tableau 3D ------\n");
}

int ***array_3D_init(size_t sizeI, size_t sizeJ, size_t sizeK) {
  int ***array = malloc(sizeI * sizeof(void **));
  for (size_t i = 0; i < sizeI; i++) {
    array[i] = malloc(sizeJ * sizeof(void *));
    for (size_t j = 0; j < sizeJ; j++) {
      array[i][j] = malloc(sizeK * sizeof(int));
      for (size_t k = 0; k < sizeK; k++) {
        array_3D_set(array, i, j, k, 0);
      }
    }
  }
  return array;
}

int array_3D_get(int ***array, size_t i, size_t j, size_t k) {
  return array[i][j][k];
  // return *(*(*(array + i) + j) + k);
}

void array_3D_set(int ***array, size_t i, size_t j, size_t k, int element) {
  array[i][j][k] = element;
  // *(*(*(array + i) + j) + k) = element;
}

void array_3D_print(int ***array, size_t sizeI, size_t sizeJ, size_t sizeK) {
  for (size_t i = 0; i < sizeI; i++) {
    for (size_t j = 0; j < sizeJ; j++) {
      for (size_t k = 0; k < sizeK; k++) {
        printf("%d ", array_3D_get(array, i, j, k));
      }
      printf("\n");
    }

    bool is_last = i == sizeI - 1;
    if (!is_last) {
      printf("\n");
    }
  }
}
