#include "square.h"

int main_square() {
  float square_side = 0.0;
  printf("Mesure côté d'un carré (réel): ");
  scanf("%f", &square_side);

  printf("Périmètre: %f\n", square_perimeter(square_side));
  printf("Surface (aire): %f\n", square_area(square_side));
  printf("Diagonale: %f\n", square_diagonal(square_side));

  return EXIT_SUCCESS;
}

float square_perimeter(float square_side) {
  return square_side * 4;
}

float square_area(float square_side) {
  return square_side * square_side;
}

float square_diagonal(float square_side) {
  return sqrt(2) * square_side;
}
