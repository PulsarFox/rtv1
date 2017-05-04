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
	v->a = pow(cam->dir[0], 2) + pow(cam->dir[1], 2) + pow(cam->dir[2], 2);
	v->b = 2 * (cam->dir[0] * (cam->x - cord->x) + cam->dir[1]
			* (cam->y - cord->y) + cam->dir[2] * (cam->z - cord->z));
	v->c = (pow((cam->x - cord->x), 2) + pow((cam->y - cord->y), 2) +
			pow((cam->z - cord->z), 2) - pow(cord->r, 2));
	if (v->a == 0.25)
		v->det = pow(v->b, 2) - v->c;
	else
		v->det = pow(v->b, 2) - (4 * v->a * v->c);
}

void		calc_sphere_norm(t_obj *cam, t_calc *v, t_obj *obj)
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
	obj->dir[0] = x * norm;
	obj->dir[1] = y * norm;
	obj->dir[2] = z * norm;
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
