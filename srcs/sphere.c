/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:55:39 by savincen          #+#    #+#             */
/*   Updated: 2017/05/04 16:29:49 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"
#include "libft.h"
#include <stdio.h>

static void		calc_sphere(t_obj *cam, t_calc *v, t_obj *cord)
{
	v->a = pow(cam->dir->x, 2) + pow(cam->dir->y, 2) + pow(cam->dir->z, 2);
	v->b = 2 * (cam->dir->x * (cam->pos->x - cord->pos->x) + cam->dir->y
			* (cam->pos->y - cord->pos->y) + cam->dir->z *
				(cam->pos->z - cord->pos->z));
	v->c = (pow((cam->pos->x - cord->pos->x), 2) + pow((cam->pos->y -
		cord->pos->y), 2) + pow((cam->pos->z - cord->pos->z), 2) -
			pow(cord->r, 2));
	if (v->a == 0.25)
		v->det = pow(v->b, 2) - v->c;
	else
		v->det = pow(v->b, 2) - (4 * v->a * v->c);
}

t_vect		*calc_sphere_norm(t_obj *cam, t_calc *v, t_obj *obj)
{
	t_vect	*base;
	t_vect	*impc;
	t_vect	*norm;

	get_impact(v, cam);
	base = copy_vect(obj->pos);
	impc = copy_vect(v->imp);
	norm = new_vect(impc->x - base->x, impc->y - base->y, impc->z - base->z);
	normalize(norm);
	return (norm);
}

int		check_sphere(t_obj *cam, t_calc *v, t_obj *obj)
{
	double	dist1;
	double	dist2;
	double	dist;

	calc_sphere(cam, v, obj);
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
