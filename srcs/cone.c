/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:28:03 by savincen          #+#    #+#             */
/*   Updated: 2017/05/18 18:32:17 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

static int		calc_cone(t_obj *cam, t_calc *v, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a = -pow(cam->dir->x, 2) + pow(cam->dir->y, 2) + pow(cam->dir->z, 2);
	b = 2 * (-(cam->dir->x * (cam->pos->x - obj->pos->x)) + cam->dir->y *
				(cam->pos->y - obj->pos->y) + cam->dir->z * (cam->pos->z -
					obj->pos->z));
	c = -pow((cam->pos->x - obj->pos->x), 2) + pow((cam->pos->y -
			obj->pos->y), 2) + pow((cam->pos->z - obj->pos->z), 2);
	if (a == 0.25)
		det = pow(b, 2) - c;
	else
		det = pow(b, 2) - (4 * a * c);
	if (det <= 0.0000001)
		return (0);
	v->dist1 = (-b + sqrt(det)) / (2 * a);
	v->dist2 = (-b - sqrt(det)) / (2 * a);
	return (1);
}

t_vect		calc_cone_norm(t_obj *obj, t_vect impact)
{
	t_vect	norm;

	norm = new_vect(impact.x - obj->pos->x, impact.y - obj->pos->y, impact.z -
			obj->pos->z);
	norm = normalize(&norm);
	return (norm);
}

int		check_cone(t_obj *cam, t_calc *v, t_obj *obj)
{
	double	dist;

	if (!calc_cone(cam, v, obj))
		return (0);
	if (v->dist1 < 0.00000001 && v->dist2 < 0.00000001)
		return (0);
	if (v->dist1 > 0.00000001 && v->dist2 > 0.00000001)
	{
		dist = v->dist2;
		if (v->dist1 < v->dist2)
			dist = v->dist1;
		if (v->t <= dist && v->t > 0.00000001)
			return (1);
		v->t = dist;
	}
	return (1);
}
