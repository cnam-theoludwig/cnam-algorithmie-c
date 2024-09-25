#include "hello.h"

int main_hello() {
  printf("Hello, world!\n");
  return EXIT_SUCCESS;
}

int main_user_input() {
  int integer = 0;
  float real = 0.0;
  printf("entier: ");
  scanf("%d", &integer);
  printf("réel: ");
  scanf("%f", &real);

  printf("entier = %d\n", integer);
  printf("réel = %f\n", real);
  return EXIT_SUCCESS;
}
