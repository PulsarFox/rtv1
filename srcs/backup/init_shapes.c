/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:19:32 by savincen          #+#    #+#             */
/*   Updated: 2017/05/23 20:28:51 by savincen         ###   ########.fr       */
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
		*obj->dir = calc_sphere_norm(obj, impact);
	else if (obj->obj_type == PLAN)
		*obj->dir = calc_plan_norm(obj, impact);
	else if (obj->obj_type == CYLINDER)
		*obj->dir = calc_cylinder_norm(obj, impact);
	else if (obj->obj_type == CONE)
		*obj->dir = calc_cone_norm(obj, impact);
}

void	set_shadows(t_calc *v, int l)
{
	int		i;

	i = l;
	while (i > 0)
	{
		v->red = v->red * 0.70;
		v->blue = v->blue * 0.70;
		v->green = v->green * 0.70;
		i--;
	}
}

void	set_light(t_obj *obj, t_calc *v, t_obj *cam)
{
	t_obj	*light;
	t_vect	vect;
	int		k;
	int		l;
	t_vect	l_normal;

	v->theta = 0;
	v->blue = 0;
	v->green = 0;
	v->red = 0;
	light = cam;
	k = 0;
	l = 0;
	vect = get_impact(v, cam->pos, cam->dir);
	check_normal(obj, vect);
	while (light)
	{
		if (light->obj_type == LIGHT)
		{
			l_normal = new_vect(vect.x - light->pos->x, vect.y -
					light->pos->y, vect.z - light->pos->z);
			light->dir = &l_normal;
			k = calc_shadow(light, v, obj, cam);
//			l_normal = new_vect(light->pos->x - vect.x, light->pos->y -
//					vect.y, light->pos->z - vect.z);
			l = l + calc_light(obj, light, v, k);
		}
		light = light->next;
	}
	set_shadows(v, l);
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
