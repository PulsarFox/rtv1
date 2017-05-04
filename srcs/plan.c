/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:57:14 by savincen          #+#    #+#             */
/*   Updated: 2017/04/13 19:58:06 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"
#include <stdio.h>

int		check_plan(t_obj *cam, t_calc *v, t_obj *cord)
{
	double		dir;
	int			xl;
	int			yl;
	int			zl;

	xl = cam->x - cord->x;
	yl = cam->y - cord->y;
	zl = cam->z - cord->z;
	dir = -((cord->dir[0] * xl + cord->dir[1] * yl + cord->dir[2] * zl)
				/ (cord->dir[0] * cam->dir[0] + cord->dir[1] * cam->dir[1]
					+ cord->dir[2] * cam->dir[2]));
	if (dir > 0.00000001 && dir < 20000)
	{
		if (v->t <= dir && v->t != 0)
			return (1);
		v->t = dir;
	}
	return (0);
}
