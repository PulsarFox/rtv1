/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 18:08:22 by savincen          #+#    #+#             */
/*   Updated: 2017/05/09 20:08:16 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

t_vect	get_impact(t_calc *v, t_vect pos, t_vect dir)
{
	t_vect	vect;

	vect = new_vect((pos.x + (dir.x * v->t)), (pos.y + (dir.y * v->t)),
		(pos.z + (dir.z * v->t)));
	return (vect);
}

void	set_color(t_calc *v, double color)
{
	v->blue = color;
	v->green = color;
	v->red = color;
}

static t_vect	get_light_norm(t_obj *light, t_vect imp)
{
	t_vect	normal;

	light->dir->x = light->pos->x - imp.x;
	light->dir->y = light->pos->y - imp.y;
	light->dir->z = light->pos->z - imp.z;
	normal = normalize(light->dir);
	return (normal);
}

int		calc_shadow(t_obj *light, t_calc *v, t_obj *current, t_obj *lstobj)
{
	t_obj	*tmp;

	tmp = lstobj;
	while (tmp)
	{
		if (tmp->obj_type != LIGHT && tmp->obj_type != CAMERA)
		{
			if (tmp->obj_type == SPHERE && tmp != current &&
				check_sphere(light, v, tmp) && v->t <= 0.99999999)
				return (1);
			else if (tmp->obj_type == PLAN && tmp != current &&
				check_plan(light, v, tmp) && v->t <= 0.99999999)
				return (1);
			else if (tmp->obj_type == CONE && tmp != current &&
				check_cone(light, v, tmp) && v->t <= 0.99999999)
				return (1);
			else if (tmp->obj_type == CYLINDER && tmp != current &&
				check_cylinder(light, v, tmp) && v->t <= 0.99999999)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		calc_light(t_obj *obj, t_obj *light, t_calc *v, t_vect vect)
{
	double	theta;

	if (obj == NULL)
	{
		set_color(v, 0);
		return (0);
	}
	*light->dir = get_light_norm(light, vect);
	theta = dot_product(light->dir, obj->dir);
	if (v->theta < theta)
	{
		v->theta = theta;
		v->red = obj->color->x * light->color->x * v->theta;
		v->green = obj->color->y * light->color->y * v->theta;
		v->blue = obj->color->z * light->color->z * v->theta;
	}
	return (1);
}
