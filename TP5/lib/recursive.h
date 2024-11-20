#ifndef __TP5_RECURSIVE__
#define __TP5_RECURSIVE__

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int recursive_suite_1(int N);

bool is_even(int number);

int recursive_suite_syracuse(int u0, int N);

void display_digit_iterative(int number);

void display_digit_recursive_helper(unsigned int number);

void display_digit_recursive(int number);

int fibonacci(int n);

int fibonacci_rec(int n, int depth);

void hanoi(int n, char from, char to, char aux, int depth);

#endif
