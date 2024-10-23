#include "calculator.h"

void calculator_main(int argc, string_t* argv) {
  printf("------ Calculatrice ------\n");
  printf("argc = %d\n", argc);
  for (int index = 0; index < argc; index++) {
    printf("argv[%d] = %s\n", index, argv[index]);
  }

  if (argc > 1) {
    printf("\n");
    int last_value = 0;
    string_t last_operation = "";
    int result = 0;
    for (int argv_index = 1; argv_index < argc; argv_index++) {
      string_t value = argv[argv_index];
      if (string_equals(value, "+") || string_equals(value, "-")) {
        last_operation = value;
      } else {
        int number = string_to_int(value);
        if (string_equals(last_operation, "+")) {
          result += last_value + number;
          last_operation = "";
          last_value = 0;
        } else if (string_equals(last_operation, "-")) {
          result += last_value - number;
          last_operation = "";
          last_value = 0;
        } else {
          last_value = number;
        }
      }
    }

    for (int index = 1; index < argc; index++) {
      printf("%s ", argv[index]);
    }
    printf("= %d\n", result);
  }

  printf("------ Calculatrice ------\n");
}
