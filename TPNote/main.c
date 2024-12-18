#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "tpnote.h"

int main() {
  printf("---TP Noté - Tests des fonctions de pile_float---\n\n");

  printf("Création d'une pile avec des blocs de taille 3 et un maximum de 10 blocs.\n");
  struct Pile* pile = new_pile(3, 10);
  if (pile == NULL) {
    printf("Erreur: Impossible de créer la pile.\n");
    return EXIT_FAILURE;
  }

  printf("\nEmpilement de valeurs...\n");
  push(pile, 1.0);
  push(pile, 4.0);
  push(pile, 42.0);
  push(pile, 54.0);
  push(pile, 23.0);

  printf("\nContenu de la pile après empilement :\n");
  dump(pile);

  printf("\nSommet de la pile : %f\n", head(pile));

  printf("\nDépilement de 2 valeurs...\n");
  pop(pile);
  pop(pile);

  printf("\nContenu de la pile après dépilement :\n");
  dump(pile);

  printf("\nLa pile est-elle vide ? %s\n", empty(pile) ? "Oui" : "Non");

  printf("\nNettoyage de la pile...\n");
  clean(pile);

  printf("\nContenu de la pile après nettoyage :\n");
  dump(pile);

  printf("\nEmpilement de nouvelles valeurs pour tester shrink...\n");
  push(pile, 10.0);
  push(pile, 20.0);
  push(pile, 30.0);
  dump(pile);

  printf("\nRéduction des blocs inutilisés avec shrink...\n");
  shrink(pile);

  printf("\nContenu de la pile après shrink :\n");
  dump(pile);

  printf("\nChangement de la taille des blocs à 5...\n");
  change_bloc_size(pile, 5);

  printf("\nContenu de la pile après changement de taille des blocs :\n");
  dump(pile);

  printf("\nDestruction de la pile...\n");
  destroy(&pile);

  printf("\nLa pile a-t-elle été détruite ? %s\n", (pile == NULL) ? "Oui" : "Non");

  return EXIT_SUCCESS;
}
