/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:28:03 by savincen          #+#    #+#             */
/*   Updated: 2017/05/24 16:46:57 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include <stdio.h>

static int		calc_cone(t_obj *cam, t_calc *v, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	double	det;
	t_vect	rot;
	t_vect	tmp;

	tmp = rotation(cam->dir, obj->rot);
	rot = new_vect(cam->pos.x - obj->pos.x, cam->pos.y - obj->pos.y,
			cam->pos.z - obj->pos.z);
	rot = rotation(rot, obj->rot);
	a = pow(tmp.z, 2) + pow(tmp.x, 2) - pow(tmp.y, 2) * obj->r;
	b = 2 * (tmp.z * rot.z + tmp.x * rot.x - (tmp.y * rot.y * obj->r));
	c = pow(rot.x, 2) + pow(rot.z, 2) - pow(rot.y, 2) * obj->r;
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
	t_vect	base;
	t_vect	tmp;

	tmp = rotation(impact, obj->rot);
	base = rotation(obj->pos, obj->rot);
	norm = new_vect(base.x - tmp.x, (base.y - tmp.y) * -obj->r, base.z - tmp.z);
	norm = inv_rotation(norm, obj->rot);
	norm = normalize(norm);
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
			return (0);
		v->t = dist;
		return (1);
	}
	return (0);
}
