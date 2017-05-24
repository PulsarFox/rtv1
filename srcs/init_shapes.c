/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:19:32 by savincen          #+#    #+#             */
/*   Updated: 2017/05/24 17:09:32 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"
#include <stdio.h>
#include <stdlib.h>

void		calc_dist(t_obj *obj, t_obj *cam, t_calc *v)
{
	if (obj->obj_type == SPHERE)
		check_sphere(cam, v, obj);
	else if (obj->obj_type == PLAN)
		check_plan(cam, v, obj);
	else if (obj->obj_type == CYLINDER)
		check_cylinder(cam, v, obj);
	else if (obj->obj_type == CONE)
		check_cone(cam, v, obj);
}

void		check_normal(t_obj *obj, t_vect impact)
{
	if (obj->obj_type == SPHERE)
		obj->dir = calc_sphere_norm(obj, impact);
	else if (obj->obj_type == CYLINDER)
		obj->dir = calc_cylinder_norm(obj, impact);
	else if (obj->obj_type == CONE)
		obj->dir = calc_cone_norm(obj, impact);
}

void		check_primitives(t_obj *obj, t_obj *cam, t_calc *v)
{
	t_obj *tmp;
	t_obj *closer;
	double	dist;

	dist = 20000;
	tmp = obj;
	closer = NULL;
	while (tmp)
	{
		if (tmp->obj_type != CAMERA && tmp->obj_type != LIGHT)
		{
			calc_dist(tmp, cam, v);
			if (dist > v->t && v->t > 0.00000001)
			{
				closer = tmp;
				dist = v->t;
			}
		}
		tmp = tmp->next;
	}
	v->t = dist;
	if (closer != NULL)
		set_light(closer, v, cam);
	else
		set_color(v, 0);
}
