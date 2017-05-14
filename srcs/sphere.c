/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:55:39 by savincen          #+#    #+#             */
/*   Updated: 2017/05/09 17:19:24 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"
#include "libft.h"
#include <stdio.h>

static int		calc_sphere(t_obj *cam, t_calc *v, t_obj *cord)
{
	double	a;
	double	b;
	double	c;
	double	det;

	a = pow(cam->dir->x, 2) + pow(cam->dir->y, 2) + pow(cam->dir->z, 2);
	b = 2 * (cam->dir->x * (cam->pos->x - cord->pos->x) + cam->dir->y
			* (cam->pos->y - cord->pos->y) + cam->dir->z *
				(cam->pos->z - cord->pos->z));
	c = (pow((cam->pos->x - cord->pos->x), 2) + pow((cam->pos->y -
		cord->pos->y), 2) + pow((cam->pos->z - cord->pos->z), 2) -
			pow(cord->r, 2));
	if (a == 0.25)
		det = pow(b, 2) - c;
	else
		det = pow(b, 2) - (4 * a * c);
	if (det <= 0)
		return (0);
	v->dist1 = (-b + sqrt(det)) / (2 * a);
	v->dist2 = (-b - sqrt(det)) / (2 * a);
	return (1);
}

t_vect		calc_sphere_norm(t_obj *cam, t_calc *v, t_obj *obj)
{
	t_vect	base;
	t_vect	impc;
	t_vect	norm;

	impc = get_impact(v, *cam->pos, *cam->dir);
	v->imp = &impc;
	base = copy_vect(obj->pos);
	norm = new_vect(impc.x - base.x, impc.y - base.y, impc.z - base.z);
	norm = normalize(&norm);
	return (norm);
}

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
/*
int		check_sphere(t_obj *cam, t_calc *v, t_obj *obj)
{
	double	dist1;
	double	dist2;

	calc_sphere(cam, v, obj);
	if (v->det < 0.00000001)
		return (0);
	else if (v->det == 0)
		dist1 = dist2 = -0.5 * v->b / v->a;
	else
	{
		dist1 = (-v->b + sqrt(v->det)) / (2 * v->a);
		dist2 = (-v->b - sqrt(v->det)) / (2 * v->a);
	}
	if (dist1 > dist2)
		ft_dswap(&dist1, &dist2);
	if (dist1 < 0.00000001)
	{
		dist1 = dist2;
		if (dist1 < 0.00000001)
			return (0);
	}
	v->t = dist1;
	return (1);
}*/
