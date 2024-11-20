# TP n°5 - Récursivité

## Suites

- faire une fonction récursive de calcul de $Un = 2 \times U_{n-1} - 1$ avec $U0 = 5$
- afficher toutes les valeurs de Un pour n de 0 à N (dans la fonction)

  - $U[0] = 5$
  - $U[1] = 9$
  - $U[2] = 17$
  - $U[3] = 33$
  - $U[4] = 65$
  - $U[5] = 129$
  - $U[6] = 257$
  - $U[7] = 513$

- Afficher la suite de Syracuse
  - $U0 = paramètre$
  - $Un+1 = Un /2$ si Un pair
  - $Un+1 = 3 \times Un + 1$ si Un impair
  - arrêt on finit toujours par boucler sur 1 4 2 1 4 2 1 4 2 1.....

## Chiffres

- Afficher (un à un) les chiffres d'un nombre passé en paramètre (int), 123456789 -> 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9
  - Essayer en itératif
  - Puis en récursif (plus simple ?)
  - bonus: comment faire pour dépasser 10 chiffres (et pourquoi est-ce un problème ?)

## Fibonacci

- implanter fibonacci en récursifs en affichant la pile des appels (utiliser sprintf)
- Déduire de l'affichage de la pile que c'est inefficace (justifier)
- écrire une version itérative
- comparer le nombres d'additions

## Les tours de Hanoi

On a trois poteaux sur lesquels on peut enficher des disque de différentes tailles.

Un disque ne peut être posé que sur un disque plus petit.

Comment optimalement déplacer n disques depuis le premier poteau vers le troisième.

Combien de temps pour déplacer 64 disques ? (combien de mouvements)

- implémenter l'affichage des déplacements des Tours de Hanoi
- on affichera la pile comme pour Fibonacci
