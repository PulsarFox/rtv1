/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 18:08:22 by savincen          #+#    #+#             */
/*   Updated: 2017/05/24 19:13:30 by savincen         ###   ########.fr       */
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
			l_normal = new_vect(vect.x - light->pos.x, vect.y -
					light->pos.y, vect.z - light->pos.z);
			light->dir = l_normal;
			k = calc_shadow(light, v, obj, cam);
			l = l + calc_light(obj, light, v, k);
		}
		light = light->next;
	}
	set_shadows(v, l);
}

int		calc_light(t_obj *obj, t_obj *light, t_calc *v, int k)
{
	double	theta;
	t_vect	l_norm;
	double	red;
	double	green;
	double	blue;

	l_norm = normalize(light->dir);
	theta = dot_product(l_norm, obj->dir);
	if (theta > 0)
	{
		if ((red = obj->color.x * light->color.x * theta) > v->red)
			v->red = red;
		if ((green = obj->color.y * light->color.y * theta) > v->green)
			v->green = green;
		if ((blue = obj->color.z * light->color.z * theta) > v->blue)
			v->blue = blue;
		if (k == 1)
			return (1);
	}
	return (0);
}
