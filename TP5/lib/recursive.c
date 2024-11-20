#include "recursive.h"

// $Un = 2 \times U_{n-1} - 1$ avec $U0 = 5$
int recursive_suite_1(int N) {
  if (N == 0) {
    int u0 = 5;
    printf("u0 = %d\n", u0);
    return u0;
  }
  int next = 2 * recursive_suite_1(N - 1) - 1;
  printf("u%d = %d\n", N, next);
  return next;
}

bool is_even(int number) {
  return number % 2 == 0;
}

int recursive_suite_syracuse(int u0, int N) {
  if (N == 0) {
    printf("u0 = %d\n", u0);
    return u0;
  }
  int last = recursive_suite_syracuse(u0, N - 1);
  if (is_even(last)) {
    int next = last / 2;
    printf("u%d = %d\n", N, next);
    return next;
  }
  int next = (3 * last) + 1;
  printf("u%d = %d\n", N, next);
  return next;
}

void display_digit_iterative(int number) {
  int current = number;
  int *digits = malloc(0);
  int count = 0;

  if (number < 0) {
    printf("-");
    current = -current;
  }

  do {
    digits = realloc(digits, (count + 1) * sizeof(int));
    digits[count++] = current % 10;
    current = current / 10;
  } while (current > 0);

  for (int i = count - 1; i >= 0; i--) {
    printf("%d", digits[i]);
  }

  free(digits);
  printf("\n");
}

void display_digit_recursive_helper(unsigned int number) {
  if (number == 0) {
    return;
  }
  display_digit_recursive_helper(number / 10);
  printf("%d", number % 10);
}

void display_digit_recursive(int number) {
  if (number < 0) {
    printf("-");
    number = -number;
  }
  if (number == 0) {
    printf("0");
  } else {
    display_digit_recursive_helper((unsigned int)number);
  }
  printf("\n");
}

int fibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  int a = fibonacci(n - 1);
  int b = fibonacci(n - 2);
  int result = a + b;
  printf("fibonacci(%d - 1) = %d\n", n, a);
  printf("fibonacci(%d - 1) = %d\n", n, b);
  printf("fibonacci(%d - 1) + fibonacci(%d - 2) = %d\n", n, n, result);
  return result;
}

int fibonacci_rec(int n, int depth) {
  char indent[depth + 1];
  sprintf(indent, "%*s", depth, "");
  printf("%sAppel: fibonacci(%d)\n", indent, n);

  if (n <= 1) {
    printf("%sRetour: %d\n", indent, n);
    return n;
  }

  int result = fibonacci_rec(n - 1, depth + 2) + fibonacci_rec(n - 2, depth + 2);
  printf("%sRetour: fibonacci(%d) = %d\n", indent, n, result);
  return result;
}

void hanoi(int n, char from, char to, char aux, int depth) {
  char indent[depth + 1];
  sprintf(indent, "%*s", depth, "");
  printf("%sDéplacer %d disque(s) de %c vers %c en utilisant %c\n", indent, n, from, to, aux);
  if (n == 1) {
    printf("%sMouvement: %c -> %c\n", indent, from, to);
    return;
  }
  hanoi(n - 1, from, aux, to, depth + 2);
  printf("%sMouvement: %c -> %c\n", indent, from, to);
  hanoi(n - 1, aux, to, from, depth + 2);
}
