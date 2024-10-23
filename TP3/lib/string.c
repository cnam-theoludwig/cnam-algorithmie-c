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

  string_t string4 = "radar";
  string_t string5 = "hello";
  printf("string4 = %s\n", string4);
  printf("string5 = %s\n", string5);
  printf("string4 is palindrome = %s\n", utils_boolean_to_string(string_palindrome(string4)));
  printf("string5 is palindrome = %s\n", utils_boolean_to_string(string_palindrome(string5)));
  printf("\n");

  string_t string6 = "Hello, World!";
  string_t string7 = "World";
  printf("string6 = %s\n", string6);
  printf("string7 = %s\n", string7);
  printf("string7 is substring of string6 at index %d\n", string_find_substring(string6, string7));
  printf("\n");

  string_t string8 = "-42";
  printf("string8 = %s\n", string8);
  printf("string8 = %d\n", string_to_int(string8));

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

bool string_palindrome(const string_t string) {
  size_t length = string_get_length(string);
  bool is_palindrome = true;
  for (size_t index = 0; index < length / 2 && is_palindrome; index++) {
    if (string[index] != string[length - index - 1]) {
      is_palindrome = false;
    }
  }
  return is_palindrome;
}

int string_find_substring(const string_t string, const string_t substring) {
  size_t string_length = string_get_length(string);
  size_t substring_length = string_get_length(substring);
  if (string_length < substring_length) {
    return -1;
  }
  size_t substring_index = 0;
  for (size_t string_index = 0; string_index < string_length; string_index++) {
    if (substring_index < substring_length && string[string_index] == substring[substring_index]) {
      substring_index += 1;
    } else {
      if (substring_index >= substring_length - 1) {
        return string_index - substring_length;
      }

      substring_index = 0;
    }
  }
  if (substring_index >= substring_length - 1) {
    return string_length - substring_length;
  }
  return -1;
}

char character_to_digit(const char character) {
  return character - '0';
}

int string_to_int(const string_t string) {
  bool is_negative = string[0] == '-';
  int64_t integer = 0;
  size_t length = string_get_length(string);
  for (size_t index = is_negative ? 1 : 0; index < length; index++) {
    integer = integer * 10 + character_to_digit(string[index]);
  }
  return is_negative ? integer * -1 : integer;
}
