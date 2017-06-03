/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:57:14 by savincen          #+#    #+#             */
/*   Updated: 2017/05/30 16:19:46 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"
#include <stdio.h>
#include "libft.h"

static	void	get_second_type(char *line, t_obj *obj)
{
	if (ft_strstr(line, "RWALL"))
	{
		obj->dir.x = 1;
		obj->dir.y = 0;
		obj->dir.z = 0;
	}
	else if (ft_strstr(line, "ROOF"))
	{
		obj->dir.x = 0;
		obj->dir.y = 1;
		obj->dir.z = 0;
	}
	else
	{
		ft_putstr("Invalid type at line\n");
		ft_putstr(line);
		ft_putchar('\n');
		exit(1);
	}
}

void		get_dir_type(char *line, t_obj *obj)
{
	if (ft_strstr(line, "BWALL"))
	{
		obj->dir.x = 0;
		obj->dir.y = 0;
		obj->dir.z = 1;
	}
	else if (ft_strstr(line, "GROUND"))
	{
		obj->dir.x = 0;
		obj->dir.y = -1;
		obj->dir.z = 0;
	}
	else if (ft_strstr(line, "LWALL"))
	{
		obj->dir.x = -1;
		obj->dir.y = 0;
		obj->dir.z = 0;
	}
	else
		get_second_type(line, obj);
}

t_vect	calc_plan_norm(t_obj *obj)
{
	t_vect	norm;

	norm = rotation(obj->dir, obj->rot);
	norm = normalize(norm);
	return (norm);
}

int		parse_plan(int fd, t_obj *obj)
{
	char	*line;

	obj->obj_type = PLAN;
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

int		check_plan(t_obj *cam, t_calc *v, t_obj *obj)
{
	double		dir;
	t_vect		vect;

	vect = new_vect(cam->pos.x - obj->pos.x, cam->pos.y - obj->pos.y,
			cam->pos.z - obj->pos.z);
	dir = -((obj->dir.x * vect.x + obj->dir.y * vect.y + obj->dir.z * vect.z)
				/ dot_product(obj->dir, cam->dir));
	if (dir > 0.00000001 && dir < COEFF)
	{
		v->t = dir;
		return (1);
	}
	return (0);
}
