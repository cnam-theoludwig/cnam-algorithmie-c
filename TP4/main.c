#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tp4project.h"

int main() {
  string_t string = "Hello, World!";
  printf("Length of \"%s\": %zu\n", string, string_get_length(string));
  return EXIT_SUCCESS;
}
