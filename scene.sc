***************************
##########
CAMERA
	position = (0, 10, -200)
	direction = DEFAULT
##########
------------

LIGHT
	position = (20, 50, 30)
	color = (1, 1, 1)
	name = "light2"
------------
LIGHT
	position = (-50, -10, 30)
	color = (1, 1, 1)


CYLINDER
	position = (0, 0, 50)
	rayon = 5
	color = (13, 114, 255)
	rotation = (0, 0, 0)

CYLINDER
	position = (0, 0, 60)
	rayon = 5
	color = (255, 114, 255)
	rotation = (0, 0, 15)


CONE
	position = (0, 0, 50)
	rayon = 5
	color = (255, 144, 230)
	rotation = (0, 0, 180)

********************

-Fichier a lire entre les ************
-osef des espaces entres les lignes

TRUC / REGLES A AJOUTER

Une seule camera 
Mettre les lumieres et ensuite les formes
Bugfix le parser pour ajouter un titre / phrases avant les premiers pointilles
NE pas faire le calcul d'une ombre quand le theta de la lumiere correspondante est negatif

