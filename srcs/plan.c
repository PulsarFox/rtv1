/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:57:14 by savincen          #+#    #+#             */
/*   Updated: 2017/05/09 19:40:12 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"
#include <stdio.h>

t_vect	calc_plan_norm(t_obj *cam, t_calc *v, t_obj *obj)
{
	t_vect	ret;
	t_vect	impact;

	v->pos = inv_rotation(cam->pos, obj->rot);
	v->dir = inv_rotation(cam->dir, obj->rot);
	impact = get_impact(v, v->pos, v->dir);
	v->imp = &impact;
	ret.x = obj->dir->x;
	ret.y = obj->dir->y;
	ret.z = obj->dir->z;
	return (ret);
}

int		check_plan(t_obj *cam, t_calc *v, t_obj *cord)
{
	double		dir;
	int			xl;
	int			yl;
	int			zl;

	xl = cam->pos->x - cord->pos->x;
	yl = cam->pos->y - cord->pos->y;
	zl = cam->pos->z - cord->pos->z;
	dir = -((cord->dir->x * xl + cord->dir->y * yl + cord->dir->z * zl)
				/ dot_product(cord->dir, cam->dir));
	if (dir > 0.00000001 && dir < 20000)
	{
		if (v->t <= dir && v->t != 0)
			return (0);
		else
		{
			v->t = dir;
			return (1);
		}
	}
	return (0);
}
