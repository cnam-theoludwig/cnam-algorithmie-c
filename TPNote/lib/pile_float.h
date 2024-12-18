#ifndef __TPNOTE_PILE_FLOAT__
#define __TPNOTE_PILE_FLOAT__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Une pile de float.
 */
struct Pile {
  /**
   * Un tableau de tableaux alloués dynamiquement (lors des empilements si nécessaire).
   */
  float** blocs;

  /**
   * Nombre de cases du tableau de blocs (ou nombre max de blocs).
   */
  size_t nombre_max_blocs;

  /**
   * Taille d'un bloc.
   */
  size_t taille_bloc;

  /**
   * Nombre de blocs alloués.
   */
  size_t nombre_blocs_alloues;

  /**
   * Indice du sommet de la pile.
   */
  size_t sommet_indice;
};

/**
 * @brief Création d'une pile vide.
 *
 * @param taille_bloc
 * @param nb_blocs
 * @return struct Pile* Un pointeur sur une pile allouée vide.
 */
struct Pile* new_pile(size_t taille_bloc, size_t nb_blocs);

/**
 * @brief Empile une donnée.
 *
 * @param pile
 * @param valeur
 * @return true si l'opération a réussi, false sinon.
 */
bool push(struct Pile* pile, float valeur);

/**
 * @brief Renvoit le sommet de la pile.
 *
 * @param pile
 * @param ok
 * @return float
 */
float head(struct Pile* pile);

/**
 * @brief Dépile (sans libérer la mémoire).
 *
 * @param pile
 * @return true si l'opération a réussi, false sinon.
 */
bool pop(struct Pile* pile);

/**
 * @brief Vérifie si la pile est vide.
 *
 * @param pile
 * @return true si la pile est vide, false sinon.
 */
bool empty(struct Pile* pile);

/**
 * @brief Affiche la taille, les pointeurs et le contenu de la pile.
 *
 * @param pile
 */
void dump(struct Pile* pile);

/**
 * @brief Nettoyage, remet la pile en état vide (libére les blocs).
 *
 * @param pile
 */
void clean(struct Pile* pile);

/**
 * @brief Détruit la pile.
 *
 * @param pile
 */
void destroy(struct Pile** pile);

/**
 * @brief Libère les blocs inutilisés.
 *
 * @param pile
 */
void shrink(struct Pile* pile);

/**
 * @brief Réorganise les données dans des blocs d'une autre taille.
 *
 * @param pile
 * @param nouvelle_taille
 */
void change_bloc_size(struct Pile* pile, size_t nouvelle_taille);

#endif
