#include "pile_float.h"

struct Pile* new_pile(size_t taille_bloc, size_t nb_blocs) {
  struct Pile* pile = malloc(sizeof(struct Pile));
  if (pile == NULL) {
    printf("Error (new_pile): malloc returned NULL\n");
    return NULL;
  }

  pile->blocs = malloc(nb_blocs * sizeof(float*));
  if (pile->blocs == NULL) {
    printf("Error (new_pile): malloc returned NULL\n");
    free(pile);
    return NULL;
  }

  for (size_t index = 0; index < nb_blocs; index++) {
    pile->blocs[index] = NULL;
  }

  pile->nombre_max_blocs = nb_blocs;
  pile->taille_bloc = taille_bloc;
  pile->nombre_blocs_alloues = 0;
  pile->sommet_indice = 0;
  return pile;
}

bool push(struct Pile* pile, float valeur) {
  if (pile == NULL) {
    printf("Error (push): Pile is NULL\n");
    return false;
  }

  size_t bloc_index = pile->sommet_indice / pile->taille_bloc;
  size_t index_in_block = pile->sommet_indice % pile->taille_bloc;

  if (bloc_index >= pile->nombre_max_blocs) {
    printf("Error (push): Pile is full\n");
    return false;
  }

  if (bloc_index >= pile->nombre_blocs_alloues) {
    pile->blocs[bloc_index] = malloc(pile->taille_bloc * sizeof(float));
    if (pile->blocs[bloc_index] == NULL) {
      printf("Error (push): malloc returned NULL\n");
      return false;
    }
    pile->nombre_blocs_alloues++;
  }

  pile->blocs[bloc_index][index_in_block] = valeur;
  pile->sommet_indice++;
  return true;
}

bool pop(struct Pile* pile) {
  if (pile == NULL || pile->sommet_indice == 0) {
    printf("Error (pop): Pile is NULL or empty\n");
    return false;
  }
  pile->sommet_indice--;
  return true;
}

bool empty(struct Pile* pile) {
  return pile == NULL || pile->sommet_indice == 0;
}

float head(struct Pile* pile) {
  if (pile == NULL || pile->sommet_indice == 0) {
    printf("Error (head): Pile is NULL or empty\n");
    return 0.0;
  }
  size_t bloc_index = (pile->sommet_indice - 1) / pile->taille_bloc;
  size_t index_in_bloc = (pile->sommet_indice - 1) % pile->taille_bloc;
  return pile->blocs[bloc_index][index_in_bloc];
}

void dump(struct Pile* pile) {
  if (pile == NULL) {
    printf("Error (dump): Pile is NULL\n");
    return;
  }

  printf("Pile:\n");
  printf("  Nombre max blocs: %zu\n", pile->nombre_max_blocs);
  printf("  Taille bloc: %zu\n", pile->taille_bloc);
  printf("  Nombre blocs alloues: %zu\n", pile->nombre_blocs_alloues);
  printf("  Sommet indice: %zu\n", pile->sommet_indice);

  for (size_t index1 = 0; index1 < pile->nombre_blocs_alloues; index1++) {
    printf("  Bloc %zu:\n", index1);
    for (size_t index2 = 0; index2 < pile->taille_bloc; index2++) {
      size_t index_global = index1 * pile->taille_bloc + index2;
      if (index_global >= pile->sommet_indice) break;
      printf("    [%zu] = %f\n", index_global, pile->blocs[index1][index2]);
    }
  }
}

void clean(struct Pile* pile) {
  if (pile == NULL) {
    printf("Error (clean): Pile is NULL\n");
    return;
  }

  for (size_t index = 0; index < pile->nombre_blocs_alloues; index++) {
    free(pile->blocs[index]);
  }
  pile->nombre_blocs_alloues = 0;
  pile->sommet_indice = 0;
}

void destroy(struct Pile** pile) {
  if (pile == NULL || *pile == NULL) {
    printf("Error (destroy): Pile is NULL\n");
    return;
  }

  clean(*pile);
  free((*pile)->blocs);
  free(*pile);
  *pile = NULL;
}

void shrink(struct Pile* pile) {
  if (pile == NULL) {
    printf("Error (shrink): Pile is NULL\n");
    return;
  }

  size_t dernier_bloc_utilise = (pile->sommet_indice == 0) ? 0 : (pile->sommet_indice - 1) / pile->taille_bloc;

  for (size_t index = dernier_bloc_utilise + 1; index < pile->nombre_blocs_alloues; index++) {
    free(pile->blocs[index]);
    pile->blocs[index] = NULL;
  }

  pile->nombre_blocs_alloues = dernier_bloc_utilise + 1;
}

void change_bloc_size(struct Pile* pile, size_t nouvelle_taille) {
  if (pile == NULL) {
    printf("Error (change_bloc_size): Pile is NULL\n");
    return;
  }

  if (nouvelle_taille == 0) {
    printf("Error (change_bloc_size): Nouvelle taille invalide\n");
    return;
  }

  struct Pile* nouvelle_pile = new_pile(nouvelle_taille, pile->nombre_max_blocs);
  if (nouvelle_pile == NULL) {
    printf("Error (change_bloc_size): Impossible d'allouer la nouvelle pile\n");
    return;
  }

  for (size_t index = 0; index < pile->sommet_indice; index++) {
    size_t bloc_index = index / pile->taille_bloc;
    size_t index_in_bloc = index % pile->taille_bloc;
    push(nouvelle_pile, pile->blocs[bloc_index][index_in_bloc]);
  }

  clean(pile);
  free(pile->blocs);

  pile->blocs = nouvelle_pile->blocs;
  pile->taille_bloc = nouvelle_taille;
  pile->nombre_blocs_alloues = nouvelle_pile->nombre_blocs_alloues;
  pile->sommet_indice = nouvelle_pile->sommet_indice;

  free(nouvelle_pile);
}
