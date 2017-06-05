#include "rtv1.h"
#include <math.h>
#include <stdlib.h>

double		dot_product(t_vect v1, t_vect v2)
{
	double	ret;

	ret = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	return (ret);
}

t_vect		normalize(t_vect v1)
{
	double	norme;
	t_vect	ret;

	norme = 1 / sqrt((pow(v1.x, 2) + pow(v1.y, 2) + pow(v1.z, 2)));
	ret.x = norme * v1.x;
	ret.y = norme * v1.y;
	ret.z = norme * v1.z;
	return (ret);
}

t_vect		copy_vect(t_vect v)
{
	t_vect	ret;

	ret.x = v.x;
	ret.y = v.y;
	ret.z = v.z;
	return (ret);
}

t_vect		new_vect(double x, double y, double z)
{
	t_vect	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_vect		diff_vect(t_vect a, t_vect b)
{
	t_vect ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return (ret);
}
