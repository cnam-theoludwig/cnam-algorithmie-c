#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tp5project.h"

int main() {
  printf("TP5\n");

  printf("---Suite n°1---\n");
  recursive_suite_1(7);
  printf("---Suite n°1---\n\n");

  printf("---Suite n°2 - Syracuse ---\n");
  recursive_suite_syracuse(15, 20);
  printf("---Suite n°2 - Syracuse ---\n\n");

  printf("---Afficher chifres---\n");
  display_digit_iterative(123456);
  display_digit_iterative(-123456);
  display_digit_iterative(1234567891);
  display_digit_recursive(1234567891);
  printf("---Afficher chifres---\n\n");

  printf("---Fibonacci---\n");
  fibonacci(7);
  int n = 6;
  printf("Fibonacci de %d (version récursive):\n", n);
  int result = fibonacci_rec(n, 0);
  printf("Résultat: %d\n", result);
  printf("---Fibonacci---\n\n");

  printf("---Hanoi---\n");
  n = 4;
  printf("Tours de Hanoi avec %d disque(s):\n", n);
  hanoi(n, 'A', 'C', 'B', 0);
  printf("---Hanoi---\n\n");

  return EXIT_SUCCESS;
}
