/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:57:14 by savincen          #+#    #+#             */
/*   Updated: 2017/05/24 16:21:49 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"
#include <stdio.h>

t_vect	calc_plan_norm(t_obj *obj)
{
	t_vect	norm;

	norm = rotation(obj->dir, obj->rot);
	norm = normalize(&norm);
	return (norm);
}

int		check_plan(t_obj *cam, t_calc *v, t_obj *obj)
{
	double		dir;
	t_vect		vect;

	vect = new_vect(cam->pos->x - obj->pos->x, cam->pos->y - obj->pos->y,
			cam->pos->z - obj->pos->z);
	dir = -((obj->dir->x * vect.x + obj->dir->y * vect.y + obj->dir->z * vect.z)
				/ dot_product(obj->dir, cam->dir, 0));
	if (dir > 0.00000001 && dir < COEFF)
	{
		if (v->t <= dir && v->t > 0.00000001)
			return (0);
		v->t = dir;
		return (1);
	}
	return (0);
}
