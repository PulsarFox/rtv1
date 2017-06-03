#include "rtv1.h"
#include <math.h>
#include <stdlib.h>

void	set_null(t_obj *obj)
{
	obj->pos.x = 0;
	obj->pos.y = 0;
	obj->pos.z = 0;
	obj->index = 0;
	obj->r = 1;
	obj->name = NULL;
	obj->dir.x = 0;
	obj->dir.y = 0;
	obj->dir.z = 0;
	obj->color.x = 255;
	obj->color.y = 255;
	obj->color.z = 255;
	obj->rot.x = 0;
	obj->rot.y = 0;
	obj->rot.z = 0;
	obj->next = NULL;
	obj->tr.x = 0;
	obj->tr.y = 0;
	obj->tr.z = 0;
}

void	set_translation(t_obj *obj, t_vect vect)
{
	if (vect.x != 0 || vect.y != 0 || vect.z != 0)
	{
		obj->pos.x += vect.x;
		obj->pos.y += vect.y;
		obj->pos.z += vect.z;
	}
}
