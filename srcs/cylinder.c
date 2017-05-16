#include "rtv1.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static int		calc_cylinder(t_obj *obj, t_obj rcam, t_calc *v)
{
	double	a;
	double	b;
	double	c;
	double	det;
	t_vect	rot;
	t_vect	tmp;
	t_vect	tmp2;

	tmp = rotation(rcam.dir, obj->rot);
	tmp2 = copy_vect(rcam.pos);
	rot = new_vect(tmp2.x - obj->pos->x, tmp2.y - obj->pos->y,
			tmp2.z - obj->pos->z);
	rot = rotation(&rot, obj->rot);
	a = (pow(tmp.x, 2) + pow(tmp.z, 2));
	b = (2 * tmp.x * rot.x) + (2 * tmp.z * rot.z);
	c = pow(rot.x, 2) + pow(rot.z, 2) - pow(obj->r, 2);
	det = pow(b, 2) - (4 * a * c);
	if (det <= 0.00000001)
		return (0);
	v->dist1 = (-b + sqrt(det)) / (2 * a);
	v->dist2 = (-b - sqrt(det)) / (2 * a);
	return (1);
}

t_vect		calc_cylinder_norm(t_obj *cam, t_calc *v, t_obj *obj)
{
	t_vect	impact;
	t_vect	norm;

	impact = get_impact(v, *cam->pos, *cam->dir);
	impact = rotation(&impact, obj->rot);
	v->imp = &impact;
	norm = new_vect(impact.x - obj->pos->x, 0, impact.z - obj->pos->z);
	norm = normalize(&norm);
	return (norm);
}

int		check_cylinder(t_obj *cam, t_calc *v, t_obj *obj)
{
	double	dist;

	if (!calc_cylinder(obj, *cam, v))
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
