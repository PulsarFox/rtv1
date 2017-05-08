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

void		calc_dist(t_obj *obj, t_obj *cam, t_calc *v)
{
	if (obj->obj_type == SPHERE)
	{
		check_sphere(cam, v, obj);
		calc_sphere_norm(cam, v, obj);
	}
	else if (obj->obj_type == PLAN)
		check_plan(cam, v, obj);
	else if (obj->obj_type == CYLINDER)
	{
		check_cylinder(cam, v, obj);
		calc_cylinder_norm(cam, v, obj);
	}
	else if (obj->obj_type == CONE)
	{
		check_cone(cam, v, obj);
		calc_cone_norm(cam, v, obj);
	}
}

void		set_light(t_obj *current, t_calc *v, t_obj *cam)
{
	t_obj	*light;

	v->theta = 0;
	v->blue = 0;
	v->green = 0;
	v->red = 0;
	light = cam;
	while (light)
	{
		if (light->obj_type == LIGHT)
			calc_light(current, light, v, cam);
		light = light->next;
	}
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
	set_light(closer, v, cam);
}

