#include "string.h"

size_t string_get_length(const string_t string) {
  size_t length = 0;
  while (string[length] != '\0') {
    length++;
  }
  return length;
}

string_t string_copy(const string_t string) {
  size_t string_length = string_get_length(string);
  string_t string_copy = malloc(sizeof(char) * (string_length + 1));
  for (size_t index = 0; index < string_length; index++) {
    string_copy[index] = string[index];
  }
  return string_copy;
}

string_t string_reverse(const string_t string) {
  size_t string_length = string_get_length(string);
  string_t string_reversed = malloc(sizeof(char) * (string_length + 1));
  for (size_t index = 0; index < string_length; index++) {
    string_reversed[index] = string[string_length - index - 1];
  }
  return string_reversed;
}

string_t string_substring(const string_t string, size_t index_start, size_t index_end) {
  size_t substring_length = index_end - index_start + 1;
  string_t result = malloc(sizeof(char) * (substring_length + 1));
  for (size_t index = 0; index < substring_length; index++) {
    result[index] = string[index_start + index];
  }
  result[substring_length] = '\0';
  return result;
}

size_t string_split(const string_t string, char separator, string_t** result) {
  size_t string_length = string_get_length(string);
  size_t index_string = 0;
  size_t index_current = 0;
  size_t index_result = 0;
  string_t current = malloc(sizeof(char) * (string_length + 1));
  if (current == NULL) {
    perror("Error (string_split)");
    exit(EXIT_FAILURE);
  }
  *result = NULL;
  while (index_string < string_length) {
    if (string[index_string] == separator) {
      current[index_current] = '\0';
      *result = realloc(*result, sizeof(string_t) * (index_result + 1));
      if (*result == NULL) {
        perror("Error (string_split)");
        exit(EXIT_FAILURE);
      }
      (*result)[index_result] = string_copy(current);
      index_result++;
      index_current = 0;
    } else {
      current[index_current] = string[index_string];
      index_current++;
    }
    index_string++;
  }
  current[index_current] = '\0';
  *result = realloc(*result, sizeof(string_t) * (index_result + 1));
  if (*result == NULL) {
    perror("Error (string_split)");
    exit(EXIT_FAILURE);
  }
  (*result)[index_result] = string_copy(current);
  free(current);
  return index_result + 1;
}

string_t* string_split_return_result(const string_t string, char separator, size_t* result_size) {
  size_t string_length = string_get_length(string);
  size_t index_string = 0;
  size_t index_current = 0;
  size_t index_result = 0;
  string_t current = malloc(sizeof(char) * (string_length + 1));
  string_t* result = NULL;
  if (current == NULL) {
    perror("Error (string_split)");
    exit(EXIT_FAILURE);
  }
  while (index_string < string_length) {
    if (string[index_string] == separator) {
      current[index_current] = '\0';
      result = realloc(result, sizeof(string_t) * (index_result + 1));
      if (result == NULL) {
        perror("Error (string_split)");
        exit(EXIT_FAILURE);
      }
      result[index_result] = string_copy(current);
      index_result++;
      index_current = 0;
    } else {
      current[index_current] = string[index_string];
      index_current++;
    }
    index_string++;
  }
  current[index_current] = '\0';
  result = realloc(result, sizeof(string_t) * (index_result + 1));
  if (result == NULL) {
    perror("Error (string_split)");
    exit(EXIT_FAILURE);
  }
  result[index_result] = string_copy(current);
  free(current);
  *result_size = index_result + 1;
  return result;
}

char convert_digit_to_character(const char digit) {
  return digit + '0';
}

string_t convert_character_to_string(const char character) {
  string_t string = malloc(sizeof(char) * 2);
  if (string == NULL) {
    perror("Error (convert_character_to_string)");
    exit(EXIT_FAILURE);
  }
  string[0] = character;
  string[1] = '\0';
  return string;
}

uint64_t mathematics_absolute_value(const int64_t number) {
  if (number >= 0) {
    return number;
  }
  return -number;
}

string_t string_int_to_string(int integer) {
  if (integer == 0) {
    return convert_character_to_string('0');
  }
  bool is_negative = integer < 0;
  size_t length = 1;
  int64_t current = mathematics_absolute_value(integer);
  while (current != 0) {
    current = current / 10;
    length++;
  }
  if (is_negative) {
    length++;
  }
  string_t string = malloc(sizeof(char) * length);
  if (string == NULL) {
    perror("Error (convert_number_to_string)");
    exit(EXIT_FAILURE);
  }
  current = mathematics_absolute_value(integer);
  size_t index = 0;
  while (current != 0) {
    string[index++] = convert_digit_to_character(current % 10);
    current = current / 10;
  }
  if (is_negative) {
    string[index++] = '-';
  }
  string[index] = '\0';
  string_reverse(string);
  return string;
}
