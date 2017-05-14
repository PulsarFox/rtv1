#include "rtv1.h"
#include <math.h>
#include <stdio.h>

t_vect	rot_z(t_vect *vect, double a)
{
	double	tmpx;
	double	tmpy;
	t_vect	ret;

	ret.x = vect->x;
	ret.y = vect->y;
	ret.z = vect->z;
	if (a != 0.0)
	{
		a = (3.141592654 * a) / 180;
		tmpx = ((vect->x) * cos(a)) + ((vect->y) * -sin(a)) + ((vect->z) * 0);
		tmpy = ((vect->x) * sin(a)) + ((vect->y) * cos(a)) + ((vect->z) * 0);
		ret.x = tmpx;
		ret.y = tmpy;
	}
	return (ret);
}

t_vect	rot_y(t_vect *vect, double a)
{
	double	tmpx;
	double	tmpz;
	t_vect	ret;

	ret.x = vect->x;
	ret.y = vect->y;
	ret.z = vect->z;
	if (a != 0.0)
	{
		a = (3.141592654 * a) / 180;
		tmpx = ((vect->x) * cos(a)) + ((vect->y) * 0) + ((vect->z) * sin(a));
		tmpz = ((vect->x) * -sin(a)) + ((vect->y) * 0) + ((vect->z) * cos(a));
		ret.x = tmpx;
		ret.z = tmpz;
	}
	return (ret);
}

t_vect	rot_x(t_vect *vect, double a)
{
	t_vect ret;
	double	tmpy;
	double	tmpz;

	ret.x = vect->x;
	ret.y = vect->y;
	ret.z = vect->z;
	if (a != 0.0)
	{
		a = (3.141592654 * a) / 180;
		tmpy = ((vect->x) * 0) + ((vect->y) * cos(a)) + ((vect->z) * -sin(a));
		tmpz = ((vect->x) * 0) + ((vect->y) * sin(a)) + ((vect->z) * cos(a));
		ret.y = tmpy;
		ret.z = tmpz;
	}
	return (ret);
}

t_vect	rotation(t_vect *vect, t_vect *angle)
{
	t_vect	ret;

	ret = rot_z(vect, angle->z);
	ret = rot_y(vect, angle->y);
	ret = rot_x(vect, angle->x);
	return (ret);
}

t_vect	inv_rotation(t_vect *vect, t_vect *angle)
{
	t_vect	ret;

	ret = rot_z(vect, -(angle->z));
	ret = rot_y(vect, -(angle->y));
	ret = rot_x(vect, -(angle->x));
	return (ret);
}
