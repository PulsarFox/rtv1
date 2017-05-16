***************************
##########
CAMERA
	position = (0, 10, 0)
	direction = DEFAULT
##########
------------

LIGHT
	position = (0, 50, 50)
	color = (1, 1, 1)
	name = "light2"
------------

LIGHT
	position = (40, 70, 140)
	color = (1, 1, 1)
	name = "light2"
------------

CYLINDER
	position = (20, 10, 110)
	rayon = 5
	color = (13, 114, 255)
	rotation = (0, 0, 60)

CYLINDER
	position = (0, 0, 90)
	rayon = 5
	color = (23, 244, 12)

PLAN
	position = (0, -10, 0)
	direction = HORIZONTAL
	color = (123, 32, 200)

********************

-Fichier a lire entre les ************
-osef des espaces entres les lignes

TRUC / REGLES A AJOUTER

Une seule camera 
Mettre les lumieres et ensuite les formes
Bugfix le parser pour ajouter un titre / phrases avant les premiers pointilles
NE pas faire le calcul d'une ombre quand le theta de la lumiere correspondante est negatif

