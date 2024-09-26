#include "utils.h"

int64_t utils_random_number(int64_t min, int64_t max) {
  return (rand() % (max - min + 1)) + min;
}

void utils_swap_int64_t(int64_t* a, int64_t* b) {
  int64_t temp = *a;
  *a = *b;
  *b = temp;
}

char* utils_boolean_to_string(bool boolean) {
  return boolean ? "true" : "false";
}
