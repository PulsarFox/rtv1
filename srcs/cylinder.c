#include "rtv1.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static int		calc_cylinder(t_obj *obj, t_obj *cam, t_calc *v)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a = (pow(cam->dir->x, 2) + pow(cam->dir->z, 2));
	b = 2 * cam->dir->x * (cam->pos->x - obj->pos->x) + 2 * cam->dir->z *
		(cam->pos->z - obj->pos->z);
	c = pow((cam->pos->x - obj->pos->x), 2) + pow((cam->pos->z -
		obj->pos->z), 2) - pow(obj->r, 2);
	det = pow(b, 2) - (4 * a * c);
	if (det <= 0.00000001)
		return (0);
	v->dist1 = (-b + sqrt(det)) / (2 * a);
	v->dist2 = (-b - sqrt(det)) / (2 * a);
	return (1);
}

t_vect		*calc_cylinder_norm(t_obj *cam, t_calc *v, t_obj *obj)
{
	t_vect	*base;
	t_vect	*impact;
	t_vect	*norm;

	impact = get_impact(v, cam);
	base = copy_vect(obj->pos);
	base->y = impact->y;
	norm = new_vect(impact->x - base->x, impact->y - base->y, impact->z -
		base->z);
	normalize(norm);
	free(impact);
	return (norm);
}

int		check_cylinder(t_obj *cam, t_calc *v, t_obj *obj)
{
	double	dist;

	if (!calc_cylinder(obj, cam, v))
		return (0);
	if (v->dist1 < 0.00000001 && v->dist2 < 0.00000001)
		return (0);
	if (v->dist1 > 0.00000001 && v->dist2 > 0.00000001)
	{
		dist = v->dist2;
		if (v->dist1 < v->dist2)
			dist = v->dist1;
		if (v->t <= dist && v->t > 0.00000001)
			return (0);
		v->t = dist;
		return (1);
	}
	return (0);
}
