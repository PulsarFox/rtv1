#include "rtv1.h"
#include <math.h>

void		calc_cone(t_obj *cam, t_calc *v, t_obj *obj)
{
	double	difx;
	double	dify;
	double	difz;

	difx = cam->pos->x - obj->pos->x;
	dify = cam->pos->y - obj->pos->y;
	difz = cam->pos->z - obj->pos->z;
	v->a = -pow(cam->dir->x, 2) + pow(cam->dir->y, 2) + pow(cam->dir->z, 2);
	v->b = 2 * (-(cam->dir->x * difx) + cam->dir->y * dify
	+ cam->dir->z * difz);
	v->c = -pow(difx, 2) + pow(dify, 2) + pow(difz, 2);
	if (v->a == 0.25)
		v->det = pow(v->b, 2) - v->c;
	else
		v->det = pow(v->b, 2) - (4 * v->a * v->c);
}

t_vect		*calc_cone_norm(t_obj *cam, t_calc *v, t_obj *obj)
{
	t_vect	*base;
	t_vect	*impc;
	t_vect	*normal;

	get_impact(v, cam);
	base = copy_vect(obj->pos);
	impc = copy_vect(v->imp);
	normal = new_vect(impc->x - base->x, impc->y - base->y, impc->z - base->z);
	normalize(normal);
	return (normal);
}

int		check_cone(t_obj *cam, t_calc *v, t_obj *obj)
{
	double	dist1;
	double	dist2;
	double	dist;

	calc_cone(cam, v, obj);
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
