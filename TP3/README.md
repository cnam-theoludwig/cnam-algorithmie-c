# TP n°3 - Les pointeurs

## Arithmétique des pointeurs

- expérimenter (vérifier en affichant les valeurs des adresses)
  - printf `%p` pour les pointeurs, `%ld` pour les entiers 64bits
  - conversion en long int puis différence pour les "vrais" valeurs !
- vérifier l'alignement de variables de différents types déclarées successivement
- vérifier l'alignement des cases d'un tableau
- vérifier l'effet de `++` sur un pointeur

## Fonction à plusieurs résultats

Faire une fonction qui calcule le min, le max, et la moyenne d'un tableau de float.

La fonction renvoit les trois résultats par trois pointeurs passés en paramètres.

## Chaînes de caractères

- `int longueur(char*)`
- `bool compare(char*, char*)`
- `bool palindrome(char*)`
- `int find_sub_string(char*, char*) // retourne la position de la sous-chaine sinon -1`
- Écrire la fonction `string_to_int` qui convertit une chaîne en l'entier correspondant
  => (Exemple `"327"` en `327`) équivalent à `atoi("327");`

## argc/argv (pointeur de pointeurs)

- `int main(int argc, char **argv)`
- afficher les paramètres du programme
- évaluer une expression simple (entiers `+` et `-`) passée en paramètre:
  => exemple `13 + 2 - 1 + -3` chaque chiffre et opération séparé par des espaces.

## Tableaux et pointeurs

- définir un tableaux d'entier 3D
- coder des fonctions d'accès à un élément d'indices `i, j, k` (get/set)
  - on n'utilisera pas `[ ]`
  - on passera en paramètre un pointeur sur la première case, `i, j, k` et ?
- faire une fonction qui initialise tout le tableau à zéro
- vérifier que l'accès par la fonction est équivalent à `[i][j][k]`

## Triangle de Pascal

- Rappel: tableau triangulaire rempli comme suit:
  - `T[0,j] = T[j,j] = 1`
  - `T[i,j] = T[i-1,j-1] + T[i-1,j]`
- on stockera les valeurs dans un tableau 1D (taille du triangle choisie à la compilation) en utilisant toutes les cases du tableau
- Coder sans utiliser l'accès par `[ ]` (utiliser les pointeurs) les fonctions suivantes:
  - remplissage du triangle
  - affichage du triangle
