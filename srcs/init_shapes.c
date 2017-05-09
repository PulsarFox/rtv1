/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:19:32 by savincen          #+#    #+#             */
/*   Updated: 2017/05/09 19:58:58 by savincen         ###   ########.fr       */
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

void		check_normal(t_obj *obj, t_obj *cam, t_calc *v)
{
	if (obj->obj_type == SPHERE)
		obj->dir = copy_vect(calc_sphere_norm(cam, v, obj));
	else if (obj->obj_type == CYLINDER)
		obj->dir = copy_vect(calc_cylinder_norm(cam, v, obj));
	else if (obj->obj_type == CONE)
		obj->dir = copy_vect(calc_cone_norm(cam, v, obj));
}

void		set_shadows(t_obj *current, t_calc *v, t_obj *cam, t_vect *vect)
{
	t_obj	*light;

	v->count = 0;
	light = cam;
	while (light)
	{
		if (light->obj_type == LIGHT)
		{
			light->dir->x = vect->x - light->pos->x;
			light->dir->y = vect->y - light->pos->y;
			light->dir->z = vect->z - light->pos->z;
			if (calc_shadow(light, v, current) && v->count <= 2)
			{
				v->count = v->count + 1;
				v->blue = v->blue * 0.7;
				v->green = v->green * 0.7;
				v->red = v->red * 0.7;
			}
		}
		light = light->next;
	}
}
void		set_light(t_obj *current, t_calc *v, t_obj *cam)
{
	t_obj	*light;
	t_vect	*vect;

	v->theta = 0;
	v->blue = 0;
	v->green = 0;
	v->red = 0;
	light = cam;
	vect = get_impact(v, cam);
	while (light)
	{
		if (light->obj_type == LIGHT)
			calc_light(current, light, v, vect);
		light = light->next;
	}
	set_shadows(current, v, cam, vect);
	free(vect);
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
	{
		check_normal(closer, cam, v);
		set_light(closer, v, cam);
	}
	else
		set_color(v, 0);
}
