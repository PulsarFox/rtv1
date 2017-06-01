***************************
##########
CAMERA
	position = (200, 130, -30)
	rotation = (20, -45, 0)
##########
------------

LIGHT
	position = (100, 50, 130)
	color = (1, 1, 1)

LIGHT
	position = (-100, 50, 20)
	color = (1, 1, 1)

LIGHT
	position = (100, 50, 120)
	color = (1, 1, 1)
-------------

PLAN
	position = (0, -2, 0)
	direction = GROUND
	color = (255, 255, 0)

SPHERE
	position = (0, 12, 100)
	color = (255, 130, 50)
	rayon = 9

SPHERE
	position = (0, -1, 100)
	color = (255, 130, 50)
	rayon = 12

SPHERE
	position = (0, 24, 100)
	color = (255, 130, 50)
	rayon = 5

CYLINDER
	position = (-20, 0, 100)
	color = (54, 255, 159)
	rayon = 5
	rotation = (0, 0, 20)

CONE
	position = (20, 10, 100)
	rayon = 5
	color = (244, 30, 80)
	rotation = (0, 90, 90)

PLAN
	position = (1, -2, 200)
	direction = BWALL

********************

-Fichier a lire entre les ************
-osef des espaces entres les lignes

TRUC / REGLES A AJOUTER

X - Une seule camera 
X - Mettre les lumieres et ensuite les formes
Bugfix le parser pour ajouter un titre / phrases avant les premiers pointilles
X - NE pas faire le calcul d'une ombre quand le theta de la lumiere correspondante est negatif


Parser bugs :

- argument detecte vide
- autre que argument passe
- color des lights a fix intensite lumiere
- limite lumiere

Parametres direction pour plan, equivalent en murs :
GROUND (sol)
ROOF (plafond)
RWALL (mur droit)
LWALL (mur gauche)
BWALL (mur fond)

