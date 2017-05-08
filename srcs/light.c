/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 18:08:22 by savincen          #+#    #+#             */
/*   Updated: 2017/05/04 18:25:45 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void	get_impact(t_calc *v, t_obj *cam)
{
	v->imp->x = cam->pos->x + (cam->dir->x * v->t);
	v->imp->y = cam->pos->y + (cam->dir->y * v->t);
	v->imp->z = cam->pos->z + (cam->dir->z * v->t);
}

void	set_color(t_calc *v, double color)
{
	v->blue = color;
	v->green = color;
	v->red = color;
}

static void	get_light_norm(t_obj *light, t_vect *imp)
{
	light->dir->x = light->pos->x - imp->x;
	light->dir->y = light->pos->y - imp->y;
	light->dir->z = light->pos->z - imp->z;
	normalize(light->dir);
}

int		calc_shadow(t_obj *cam, t_obj *light, t_calc *v, t_obj *current)
{
	t_obj	*tmp;
	int		chck;

	chck = 0;
	tmp = cam;
	light->dir->x = v->imp->x - light->pos->x;
	light->dir->y = v->imp->y - light->pos->y;
	light->dir->z = v->imp->z - light->pos->z;
	while (tmp)
	{
		if (tmp->obj_type == SPHERE && tmp != current &&
				check_sphere(light, v, tmp))
				chck = 1;
		else if (tmp->obj_type == PLAN && tmp != current &&
				check_plan(light, v, tmp))
				chck = 1;
		else if (tmp->obj_type == CONE && tmp != current &&
				check_cone(light, v, tmp))
				chck = 1;
		else if (tmp->obj_type == CYLINDER && tmp != current &&
				check_cylinder(light, v, tmp))
				chck = 1;
		tmp = tmp->next;
	}
	return (chck);
}

int		calc_light(t_obj *obj, t_obj *light, t_calc *v, t_obj *cam)
{
	double	theta;

	if (obj == NULL)
	{
		set_color(v, 0);
		return (0);
	}
	get_impact(v, cam);
	get_light_norm(light, v->imp);
	theta = dot_product(light->dir, obj->dir);
	if (v->theta < theta)
	{
		v->theta = theta;
		v->blue = obj->color->x * light->color->x * v->theta;
		v->green = obj->color->y * light->color->y * v->theta;
		v->red = obj->color->z * light->color->z * v->theta;
	}
	return (1);
}
