#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tp3project.h"

int main(int argc, string_t* argv) {
  utils_main_experimentation();
  printf("\n");

  utils_main_function_mutiple_results();
  printf("\n");

  string_main();
  printf("\n");

  calculator_main(argc, argv);
  printf("\n");

  return EXIT_SUCCESS;
}
