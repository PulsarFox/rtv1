***************************
##########
CAMERA
	position = (0, 10, -200)
	direction = DEFAULT
##########
------------

LIGHT
	position = (20, 40, 100)
	color = (1, 1, 1)
	name = "light2"
------------

CYLINDER
	position = (15, 10, 120)
	rayon = 10
	color = (13, 114, 255)
	rotation = (0, 0, 90)

CYLINDER
	position = (-10, 30, 140)
	rayon = 5
	color = (255, 114, 255)
	rotation = (0, 0, 180)

CYLINDER
	position = (30, 30, 160)
	rayon = 5
	color = (0, 255, 255)
	rotation = (0, 0, 45)

CYLINDER
	position = (0, 0, 100)
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

