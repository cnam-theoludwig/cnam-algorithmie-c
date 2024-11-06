# TP n°4 - Allocation dynamique

## Chaînes de caractères (avec création)

- `char* copy(const char* chaine)`
- `char* reverse(const char* chaine)`, renvoie une chaîne qui est le miroir du paramètre
- `char* sub_string(const char* chaine, int pos, int len)`
- `int decoupe(const char* chaine, char sepa, char*** souschaines)`
  - découpe une chaîne de caractère remplit un tableau de sous-chaines et en renvoie le nombre. sepa est le délimiteur de sous-chaînes
  - souschaines est le tableau (résultat) de chaînes à remplir ? Pourquoi `char***`
  - proposer une fonction qui permette de libérer la mémoire de souschaines
- `char* int_to_string(int val)`, convertit un entier en une chaîne qui contient cet entier. 347 -> "347"

Remarque: on n'oubliera pas de libérer la mémoire allouée !

## Const

Le qualifieur const permet d'indiquer au compilateur qu'une variable n'est plus modifiable après son initialisation.

Par exemple dans le corps fonction `char* copy( const char* chaine)` on ne pourra pas modifier ce qui est pointé par chaine. C'est un garde fou !
