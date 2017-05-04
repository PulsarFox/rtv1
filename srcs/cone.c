#include "rtv1.h"
#include <math.h>

void		calc_cone(t_obj *cam, t_calc *v, t_obj *obj)
{
	double	difx;
	double	dify;
	double	difz;

	difx = cam->x - obj->x;
	dify = cam->y - obj->y;
	difz = cam->z - obj->z;
	v->a = -pow(cam->dir[0], 2) + pow(cam->dir[1], 2) + pow(cam->dir[2], 2);
	v->b = 2 * (-(cam->dir[0] * difx) + cam->dir[1] * dify
	+ cam->dir[2] * difz);
	v->c = -pow(difx, 2) + pow(dify, 2) + pow(difz, 2);
	if (v->a == 0.25)
		v->det = pow(v->b, 2) - v->c;
	else
		v->det = pow(v->b, 2) - (4 * v->a * v->c);
}

static void		calc_norm(t_obj *cam, t_calc *v, t_obj *obj)
{
	double	x;
	double	y;
	double	z;
	double	norm;

	get_impact(v, cam);
	x = v->impx - obj->x;
	y = v->impy - obj->y;
	z = v->impz - obj->z;
	norm = 1 / sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	obj->dir[0] = x * fabs(norm);
	obj->dir[1] = y * fabs(norm);
	obj->dir[2] = z * fabs(norm);
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
		calc_norm(cam, v, obj);
	}
	return (1);
}
