#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "tp1project.h"

int main() {
  printf("Choisissez un exercice: \n");
  printf("1. Faire un `hello.c` et le compiler.\n");
  printf("2. Entrer au clavier un entier et un réel et les afficher.\n");
  printf("3. À partir du côté d'un carré, afficher le périmètre, la surface et la diagonale.\n");
  printf("4. Afficher le nombre de jour d'un mois.\n");
  printf("5. Calculer une durée en secondes entre 2 dates.\n");
  printf("6. Calculer le lendemain d'une date.\n");
  printf("******************************\n");
  printf("Choix du programme (numéro): ");
  int choice;
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      return main_hello();
      break;
    case 2:
      return main_user_input();
      break;
    case 3:
      return main_square();
      break;
    case 4:
      return main_days_of_month();
      break;
    case 5:
      return main_duration_between_2_dates();
      break;
    case 6:
      return main_tomorrow_date();
      break;
    default:
      printf("Veuillez sélectionner un choix valide.\n");
      break;
  }
  return EXIT_SUCCESS;
}
