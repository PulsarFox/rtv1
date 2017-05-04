/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:19:32 by savincen          #+#    #+#             */
/*   Updated: 2017/05/04 18:26:19 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"
#include <stdio.h>
#include <stdlib.h>

void		check_primitives(t_obj *obj, t_obj *cam, t_calc *v)
{
	t_obj *tmp;
	t_obj *closer;
	t_obj *light;
	double	dist;

	dist = 20000;
	light = obj;
	tmp = obj;
	closer = NULL;
	while (tmp)
	{
		if (tmp->obj_type == SPHERE)
		{
			check_sphere(cam, v, tmp);
			calc_sphere_norm(cam, v, tmp);
			if (dist > v->t && v->t > 0.00000001)
			{
				closer = tmp;
				dist = v->t;
			}
		}
		else if (tmp->obj_type == PLAN)
		{
			check_plan(cam, v, tmp);
			if (dist > v->t && v->t > 0.00000001)
			{
				closer = tmp;
				dist = v->t;
			}
		}
		else if (tmp->obj_type == CYLINDER)
		{
			check_cylinder(cam, v, tmp);
			calc_cylinder_norm(cam, v, tmp);
			if (dist > v->t && v->t > 0.00000001)
			{
				closer = tmp;
				dist = v->t;
			}
		}
		else if (tmp->obj_type == CONE)
		{
			check_cone(cam, v, tmp);
			calc_cone_norm(cam, v, tmp);
			if (dist > v->t && v->t > 0.00000001)
			{
				closer = tmp;
				dist = v->t;
			}
		}
		tmp = tmp->next;
	}
	v->t = dist;
	v->theta = 0;
	while (light)
	{
		if (light->obj_type == LIGHT)
			calc_light(closer, light, v, obj);
		light = light->next;
	}
}

