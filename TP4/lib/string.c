#include "string.h"

size_t string_get_length(const string_t string) {
  size_t length = 0;
  while (string[length] != '\0') {
    length++;
  }
  return length;
}
