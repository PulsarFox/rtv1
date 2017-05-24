#include "rtv1.h"
#include <math.h>
#include <stdio.h>

t_vect	rot_z(t_vect vect, double a)
{
	double	tmpx;
	double	tmpy;
	t_vect	ret;

	a = a * (M_PI / 180);
	tmpx = ((vect.x) * cos(a)) + ((vect.y) * -sin(a)) + ((vect.z) * 0);
	tmpy = ((vect.x) * sin(a)) + ((vect.y) * cos(a)) + ((vect.z) * 0);
	ret.z = vect.z;
	ret.x = tmpx;
	ret.y = tmpy;
	return (ret);
}

t_vect	rot_y(t_vect vect, double a)
{
	double	tmpx;
	double	tmpz;
	t_vect	ret;

	a = a * (M_PI / 180);
	tmpx = ((vect.x) * cos(a)) + ((vect.y) * 0) + ((vect.z) * sin(a));
	tmpz = ((vect.x) * -sin(a)) + ((vect.y) * 0) + ((vect.z) * cos(a));
	ret.x = tmpx;
	ret.y = vect.y;
	ret.z = tmpz;
	return (ret);
}

t_vect	rot_x(t_vect vect, double a)
{
	t_vect ret;
	double	tmpy;
	double	tmpz;

	a = a * (M_PI / 180);
	tmpy = ((vect.x) * 0) + ((vect.y) * cos(a)) + ((vect.z) * -sin(a));
	tmpz = ((vect.x) * 0) + ((vect.y) * sin(a)) + ((vect.z) * cos(a));
	ret.x = vect.x;
	ret.y = tmpy;
	ret.z = tmpz;
	return (ret);
}

t_vect	rotation(t_vect vect, t_vect angle)
{
	t_vect	ret;

	ret = rot_x(vect, angle.x);
	ret = rot_y(ret, angle.y);
	ret = rot_z(ret, angle.z);
	return (ret);
}

t_vect	inv_rotation(t_vect vect, t_vect angle)
{
	t_vect	ret;

	ret = rot_x(vect, -(angle.x));
	ret = rot_y(ret, -(angle.y));
	ret = rot_z(ret, -(angle.z));
	return (ret);
}
