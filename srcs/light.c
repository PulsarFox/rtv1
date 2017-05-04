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
	v->impx = cam->x + (cam->dir[0] * v->t);
	v->impy = cam->y + (cam->dir[1] * v->t);
	v->impz = cam->z + (cam->dir[2] * v->t);
}

void	set_color(t_calc *v, double color)
{
	v->blue = color;
	v->green = color;
	v->red = color;
}

static void	get_light_norm(t_obj *light, t_calc *v)
{
	double	norme;

	light->dir[0] = light->x - v->impx;
	light->dir[1] = light->y - v->impy;
	light->dir[2] = light->z - v->impz;
	norme = 1 / sqrt(pow(light->dir[0], 2) + pow(light->dir[1], 2)
			+ pow(light->dir[2], 2));
	light->dir[0] = light->dir[0] * norme;
	light->dir[1] = light->dir[1] * norme;
	light->dir[2] = light->dir[2] * norme;
}

void	calc_shadow(t_obj *cam, t_obj *light, t_calc *v, t_obj *current)
{
	t_obj	*tmp;
	int		chck;

	chck = 0;
	tmp = cam;
	light->dir[0] = v->impx - light->x;
	light->dir[1] = v->impy - light->y;
	light->dir[2] = v->impz - light->z;
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
	if (chck == 1 && v->t < 0.99999999)
	{
		v->blue = current->color[0] / 5;
		v->green = current->color[1] / 5;
		v->red = current->color[2] / 5;
		set_color(v, 0);
	}
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
	get_light_norm(light, v);
	theta = light->dir[0] * obj->dir[0] + light->dir[1] * obj->dir[1]
		+ light->dir[2] * obj->dir[2];
	if (v->theta < theta)
	{
		v->theta = theta;
		v->blue = obj->color[0] * light->color[0] * v->theta;
		v->green = obj->color[1] * light->color[1] * v->theta;
		v->red = obj->color[2] * light->color[2] * v->theta;
	}
	return (1);
}
