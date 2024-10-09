#include "dutch_flag.h"

char colors[3] = {'R', 'W', 'B'};

char* dutch_flag_generate_random(size_t size) {
  char* flag = malloc(size * sizeof(char));
  for (size_t index = 0; index < size; index++) {
    flag[index] = colors[utils_random_number(0, 2)];
  }
  return flag;
}

void dutch_flag_print_color(char color) {
  switch (color) {
    case 'R':
      printf("\033[0;31m■");
      break;
    case 'W':
      printf("\033[0;37m■");
      break;
    case 'B':
      printf("\033[0;34m■");
      break;
    default:
      break;
  }
}

void dutch_flag_print(char* flag, size_t size) {
  for (size_t index = 0; index < size; index++) {
    dutch_flag_print_color(flag[index]);
  }
  printf("\033[0m");
  printf("\n");
}

void dutch_flag_solution(char* flag, size_t size) {
  if (size <= 0) {
    return;
  }
  size_t red_colors_count = 0;
  size_t white_colors_count = 0;
  size_t blue_colors_count = 0;

  for (size_t index = 0; index < size; index++) {
    char color = flag[index];
    switch (color) {
      case 'R':
        red_colors_count += 1;
        break;
      case 'W':
        white_colors_count += 1;
        break;
      case 'B':
        blue_colors_count += 1;
        break;
      default:
        break;
    }
  }

  size_t index_total = 0;

  for (size_t index = 0; index < red_colors_count; index++) {
    flag[index_total] = colors[0];
    index_total += 1;
  }

  for (size_t index = 0; index < white_colors_count; index++) {
    flag[index_total] = colors[1];
    index_total += 1;
  }

  for (size_t index = 0; index < blue_colors_count; index++) {
    flag[index_total] = colors[2];
    index_total += 1;
  }
}

void dutch_flag_solution_optimized(char* flag, size_t size) {
  if (size <= 0) {
    return;
  }
  size_t red_colors_index = 0;
  size_t white_colors_index = 0;
  size_t blue_colors_index = size - 1;
  while (white_colors_index <= blue_colors_index) {
    char color = flag[white_colors_index];
    switch (color) {
      case 'W':
        white_colors_index += 1;
        break;
      case 'R':
        utils_swap_char(&flag[white_colors_index], &flag[red_colors_index]);
        red_colors_index += 1;
        white_colors_index += 1;
        break;
      case 'B':
        utils_swap_char(&flag[white_colors_index], &flag[blue_colors_index]);
        blue_colors_index -= 1;
        break;
      default:
        break;
    }
  }
}
