/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 18:08:22 by savincen          #+#    #+#             */
/*   Updated: 2017/05/23 20:28:49 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

t_vect	get_impact(t_calc *v, t_vect *pos, t_vect *dir)
{
	t_vect	vect;

	vect = new_vect((pos->x + (dir->x * v->t)), (pos->y + (dir->y * v->t)),
		(pos->z + (dir->z * v->t)));
	return (vect);
}

void	set_color(t_calc *v, double color)
{
	v->blue = color;
	v->green = color;
	v->red = color;
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

int		calc_light(t_obj *obj, t_obj *light, t_calc *v, int k)
{
	double	theta;
	t_vect	l_norm;
	double	red;
	double	green;
	double	blue;

	l_norm = normalize(light->dir);
	theta = dot_product(&l_norm, obj->dir, obj->obj_type);
	if (theta > 0)
	{
		if ((red = obj->color->x * light->color->x * theta) > v->red)
			v->red = red;
		if ((green = obj->color->y * light->color->y * theta) > v->green)
			v->green = green;
		if ((blue = obj->color->z * light->color->z * theta) > v->blue)
			v->blue = blue;
		if (k == 1)
			return (1);
	}
	return (0);
}
