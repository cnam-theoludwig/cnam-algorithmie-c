#include "string.h"

void string_main() {
  printf("------ Chaîne de caractères ------\n");
  string_t string1 = "Hello, World!";
  string_t string2 = "Hello, World!";
  string_t string3 = "Hello, world";
  printf("string1 = %s\n", string1);
  printf("string2 = %s\n", string2);
  printf("string3 = %s\n", string3);

  printf("string1 == string2 = %s\n", utils_boolean_to_string(string_equals(string1, string2)));
  printf("string1 == string3 = %s\n", utils_boolean_to_string(string_equals(string1, string3)));
  printf("\n");

  printf("------ Chaîne de caractères ------\n");
}

size_t string_get_length(const string_t string) {
  size_t length = 0;
  while (string[length] != '\0') {
    length++;
  }
  return length;
}

bool string_equals(const string_t string1, const string_t string2) {
  size_t string1_length = string_get_length(string1);
  size_t string2_length = string_get_length(string2);
  bool is_equal = string1_length == string2_length;
  for (size_t index = 0; index < string1_length && is_equal; index++) {
    if (string1[index] != string2[index]) {
      is_equal = false;
    }
  }
  return is_equal;
}
