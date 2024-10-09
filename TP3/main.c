#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tp3project.h"

int main() {
  utils_main_experimentation();
  printf("\n");

  utils_main_function_mutiple_results();
  printf("\n");

  string_main();
  return EXIT_SUCCESS;
}
