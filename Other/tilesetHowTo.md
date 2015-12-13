#background
utilisation de unsigned char pour faire la carte du background

#objets
0. 'o' (lettre o)
1. <unsigned char> identifiant de l'objet (unique dans le niveau)
2. <unsigned char> id de l'objet
3. <int> position X
4. ':'
5. <int> position Y

#detecteurs de feu
0. 'f' (lettre f)
1. <unsigned char> identifiant du detecteur (unique dans le niveau, peut être le même que celui d'un object)

#piece
0. 'r' (lettre r)
1. liste d'<unsigned char> : identifiants des objets contenus dans la pièce
2. ':'
3. liste d'<unsigned char> : identifiants des détecteurs de feu contenus dans la pièce

#id d'objets
'a' - lit
'b' - canapé
'c' - toilette
'd' - table
'e' - four
'f' - frigo
