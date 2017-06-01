***************************
##########
CAMERA
	position = (0, 20, -150)
	rotation = (0, 0, 0)
##########
------------

LIGHT
	position = (0, 20, 150)
	color = (1, 1, 1)

LIGHT
	position = (0, 90, 100)
	color = (1, 1, 1)

LIGHT
	position = (-40, 20, 150)
	color = (1, 1, 1)

LIGHT
	position = (40, 20, 150)
	color = (1, 1, 1)

SPHERE
	position = (0, 20, 190)
	rayon = 5
	color = (255, 0, 255)

CONE
	position = (0, 20, 190)
	rayon = 2
	color = (0, 40, 255)
	rotation = (0, 0, -45)

CONE
	position = (0, 20, 190)
	rayon = 2
	color = (0, 40, 255)
	rotation = (0, 0, 45)

CYLINDER
	position = (-40, 30, 100)
	rayon = 7
	color = (244, 30, 80)
	rotation = (-45, 0, 0)

SPHERE
	position = (0, -5, 100)
	rayon = 7
	color = (45, 250, 140)

CYLINDER
	position = (0, 15, 150)
	rayon = 3
	rotation = (0, 0, 90)

CYLINDER
	position = (40, 30, 100)
	rayon = 7
	color = (244, 30, 80)
	rotation = (-45, 0, 0)

PLAN
	position = (0, -20, 0)
	direction = GROUND
	color = (24, 244, 130)

PLAN
	position = (0, 0, 250)
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
- limite lumieres
- detecte pas la fin de fichier
- titre faute orthographe

Parametres direction pour plan, equivalent en murs :
GROUND (sol)
ROOF (plafond)
RWALL (mur droit)
LWALL (mur gauche)
BWALL (mur fond)

