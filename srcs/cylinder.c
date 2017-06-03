/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:27:43 by savincen          #+#    #+#             */
/*   Updated: 2017/06/01 18:21:31 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int		parse_cylinder(int fd, t_obj *obj)
{
	char	*line;

	obj->obj_type = CYLINDER;
	set_null(obj);
	while (get_next_line(fd, &line) == 1 && check_type(line) != LINE)
	{
		if (check_type(line) == SPACE || check_type(line) == PARAMETER)
			read_line(line, obj);
		else if (check_type(line) == DELIMITER)
			return (2);
		else if (check_type(line) == TITLE)
			ft_syntax_error(line, 1);
		free(line);
	}
	free(line);
	return (1);
}

static int		calc_cylinder(t_obj *obj, t_obj *rcam, t_calc *v)
{
	double	a;
	double	b;
	double	c;
	double	det;
	t_vect	rot;
	t_vect	tmp;

	tmp = rotation(rcam->dir, obj->rot);
	rot = new_vect(rcam->pos.x - obj->pos.x, rcam->pos.y - obj->pos.y,
			rcam->pos.z - obj->pos.z);
	rot = rotation(rot, obj->rot);
	a = (pow(tmp.x, 2) + pow(tmp.z, 2));
	b = (2 * tmp.x * rot.x) + (2 * tmp.z * rot.z);
	c = pow(rot.x, 2) + pow(rot.z, 2) - pow(obj->r, 2);
	det = pow(b, 2) - (4 * a * c);
	if (det < 0.00000001)
		return (0);
	v->dist1 = (-b + sqrt(det)) / (2 * a);
	v->dist2 = (-b - sqrt(det)) / (2 * a);
	return (1);
}

t_vect		calc_cylinder_norm(t_obj *obj, t_vect impact)
{
	t_vect	norm;
	t_vect	base;
	t_vect	tmp;

	tmp = rotation(impact, obj->rot);
	//tmp = copy_vect(impact);
	base = rotation(obj->pos, obj->rot);
	//base = copy_vect(obj->pos);
	norm = new_vect(base.x - tmp.x, 0, base.z - tmp.z);
	norm = normalize(norm);
	norm = inv_rotation(norm, obj->rot);
	return (norm);
}

int		check_cylinder(t_obj *cam, t_calc *v, t_obj *obj)
{
	double	dist;

	dist = 0;
	if (!calc_cylinder(obj, cam, v))
		return (0);
	if (v->dist1 > 0.00000001 && v->dist1 < COEFF)
		dist = v->dist1;
	if (v->dist2 > 0.00000001 && v->dist2 < COEFF)
	{
		if (v->dist2 <= dist)
			dist = v->dist2;
	}
	if (dist == 0)
		return (0);
	v->t = dist;
	return (1);
}
