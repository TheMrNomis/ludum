#background
utilisation de unsigned char pour faire la carte du background

#objets
1. 'o' (lettre o)
2. <unsigned char> identifiant de l'objet (unique dans le niveau)
3. <unsigned char> id de l'objet
4. <int> position X
5. <int> position Y

#detecteurs de feu
1. 'f' (lettre f)
2. <unsigned char> identifiant du detecteur (unique dans le niveau, peut être le même que celui d'un object)

#piece
1. 'r' (lettre r)
2. liste d'<unsigned char> : identifiants des objets contenus dans la pièce
3. ':'
4. liste d'<unsigned char> : identifiants des détecteurs de feu contenus dans la pièce

#id d'objets
'a' - lit
'b' - canapé
'c' - toilette
'd' - table
'e' - four
'f' - frigo
