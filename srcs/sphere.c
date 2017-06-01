/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:55:39 by savincen          #+#    #+#             */
/*   Updated: 2017/05/30 16:17:29 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"
#include "libft.h"
#include <stdio.h>

static int		calc_sphere(t_obj *cam, t_calc *v, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	double	det;
	t_vect	vect;

	vect = new_vect(cam->pos.x - obj->pos.x, cam->pos.y - obj->pos.y,
			cam->pos.z - obj->pos.z);
	a = pow(cam->dir.x, 2) + pow(cam->dir.y, 2) + pow(cam->dir.z, 2);
	b = 2 * (cam->dir.x * vect.x + cam->dir.y * vect.y + cam->dir.z * vect.z);
	c = (pow(vect.x, 2) + pow(vect.y, 2) + pow(vect.z, 2) - pow(obj->r, 2));
	det = pow(b, 2) - (4 * a * c);
	if (det < 0.00000001)
		return (0);
	v->dist1 = (-b + sqrt(det)) / (2 * a);
	v->dist2 = (-b - sqrt(det)) / (2 * a);
	return (1);
}

t_vect		calc_sphere_norm(t_obj *obj, t_vect impact)
{
	t_vect	norm;

	norm = new_vect(obj->pos.x - impact.x, obj->pos.y - impact.y, obj->pos.z -
			impact.z);
	norm = normalize(norm);
	return (norm);
}
/*
int		check_sphere(t_obj *cam, t_calc *v, t_obj *obj)
{
	double	dist;

	if (!calc_sphere(cam, v, obj))
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
*/
int		check_sphere(t_obj *cam, t_calc *v, t_obj *obj)
{
	double	dist;

	dist = 0;
	if (!calc_sphere(cam, v, obj))
		return (0);
	if (v->dist1 > 0.00000001 && v->dist1 < COEFF)
		dist = v->dist1;
	if (v->dist2 > 0.00000001 && v->dist2 < COEFF)
	{
		if (v->dist2 <= dist)
			dist = v->dist2;
	}
	if (dist == 0)
		return (0);
	v->t = dist;
	return (1);
}
