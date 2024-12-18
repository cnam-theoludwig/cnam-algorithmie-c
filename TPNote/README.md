# TP Noté

## À propos

Code réalisé par [Théo LUDWIG](https://theoludwig.fr) dans le cadre de la formation [Ingénieur en Informatique et Systèmes d'Information (SI), CNAM](https://www.itii-alsace.fr/formations/informatique-et-systemes-dinformation-le-cnam/), pour le module Algorithmie en C.

### Prérequis

- [GNU coreutils](https://www.gnu.org/software/coreutils/)
- [GNU binutils](https://www.gnu.org/software/binutils/)
- [GNU gcc](https://gcc.gnu.org/)
- [GNU make](https://www.gnu.org/software/make/)
- [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html)

### Utilisation

```sh
# Compiler le programme
make

# Compiler et exécuter le programme
make run
```

## Sujet

Le but est d'implémenter et tester une pile de `float` qui sera stockée dans un tableau de tableaux alloués dynamiquement (donc `float**`). Les blocs mémoire seront alloués lors des empilements (si nécessaire).

### Code

- Séparer déclarations et définitions dans des fichiers `.h` et `.c`
- Afficher des messages d'erreurs quand cela est nécessaire.
- Bien commentr votre code
- Implémenter le plus de test possibles (fichiers séparés)
- Faire un `Makefile` ou un `CmakeLists.txt`
- Faire une `lib`

Pour les tests, on utilisera des tailles et nombres de blocs très petits (4 et 3 par exemple).

Merci de rendre votre TP sous la forme d'un zip d'un répertoire zippé contenant uniquement les sources (et `Makefile` ou `CmakeLists.txt`) et dont le nom est `TP_Pile_votrenom`.

### Définir un type `Pile`

- les blocs `float**`
- le nombre de cases du tableau de blocs (ou nombre max de blocs)
- la taille des blocs
- le nombre de blocs alloué
- l'indice du sommet de la pile

Pour trouver la bloc et l'indice dans le bloc à partir d'un indice global (comme le sommet), vous utiliserez `/` et `%`.

### Implémenter les fonctions suivantes

- `new_pile` : création d'une pile vide

  - paramètres : taille des blocs, nb blocs
  - retourne un pointeur sur une Pile allouée vide

- `push` : empile une donnée

  - paramètres : pointeur de pile, donnée à empiler
  - retourne booléen ok ou pas (message d'erreur)

- `head` : renvoit le sommet de la pile

  - paramètres : pointeur de pile
  - retourne le sommet

- `pop` : dépile (sans libérer la mémoire)

  - paramètres : pointeur de pile
  - retourne booléen ok ou pas (message d'erreur)

- `empty` : test si vide

  - paramètres : pointeur de pile
  - retourne vrai si la pile est vide

- `dump` : affiche la taille, les pointeurs et le contenu de la pile

  - paramètres : pointeur de pile

- `clean` : nettoyage remet la pile en état vide (libère les blocs)

  - paramètres : pointeur de pile

- `destroy` : détruit la pile

  - paramètres : pointeur de pointeur de pile !

- `shrink` : libère les blocs inutilisés
- paramètres : pointeur de pile

- `change_bloc_size` : réorganise les données dans des blocs d'une autre taille
  - paramètres : taille des blocs
