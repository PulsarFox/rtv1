#include "rtv1.h"
#include <math.h>

static void		calc_cylinder(t_obj *obj, t_obj *cam, t_calc *v)
{
	v->a = (pow(cam->dir->x, 2) + pow(cam->dir->z, 2));
	v->b = 2 * cam->dir->x * (cam->pos->x - obj->pos->x) + 2 * cam->dir->z *
		(cam->pos->z - obj->pos->z);
	v->c = pow((cam->pos->x - obj->pos->x), 2) + pow((cam->pos->z -
		obj->pos->z), 2) - pow(obj->r, 2);
	if (v->a == 0.25)
		v->det = pow(v->b, 2) - v->c;
	else
		v->det = pow(v->b, 2) - (4 * v->a * v->c);
}

void		calc_cylinder_norm(t_obj *cam, t_calc *v, t_obj *obj)
{
	t_vect	*base;
	t_vect	*impact;
	t_vect	*norm;

	get_impact(v, cam);
	base = copy_vect(obj->pos);
	impact = copy_vect(v->imp);
	base->y = impact->y;
	norm = new_vect(impact->x - base->x, impact->y - base->y, impact->z -
		base->z);
	normalize(norm);
}

int		check_cylinder(t_obj *cam, t_calc *v, t_obj *obj)
{
	double	dist1;
	double	dist2;
	double	dist;

	calc_cylinder(obj, cam, v);
	if (v->det <= 0)
		return (0);
	dist1 = (-v->b + sqrt(v->det)) / (2 * v->a);
	dist2 = (-v->b - sqrt(v->det)) / (2 * v->a);
	if (dist1 < 0.00000001 && dist2 < 0.00000001)
		return (0);
	if (dist1 > 0.00000001 && dist2 > 0.00000001)
	{
		dist = dist2;
		if (dist1 < dist2)
			dist = dist1;
		if (v->t <= dist && v->t > 0.00000001)
			return (1);
		v->t = dist;
	}
	return (1);
}
