/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:57:14 by savincen          #+#    #+#             */
/*   Updated: 2017/05/19 17:43:30 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"
#include <stdio.h>

t_vect	calc_plan_norm(t_obj *obj, t_vect impact)
{
	t_vect	norm;

	(void)impact;
	norm = new_vect(obj->dir->x, obj->dir->y, obj->dir->z);
	norm.xt = -norm.x;
	norm.yt = -norm.y;
	norm.zt = -norm.z;
	return (norm);
}

int		check_plan(t_obj *cam, t_calc *v, t_obj *obj)
{
	double		dir;
	int			xl;
	int			yl;
	int			zl;

	xl = cam->pos->x - obj->pos->x;
	yl = cam->pos->y - obj->pos->y;
	zl = cam->pos->z - obj->pos->z;
	dir = -((obj->dir->x * xl + obj->dir->y * yl + obj->dir->z * zl)
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
