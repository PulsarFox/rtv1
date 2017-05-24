/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:55:41 by savincen          #+#    #+#             */
/*   Updated: 2017/05/24 16:56:52 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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


