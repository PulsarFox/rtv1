/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_primitive_list_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:47:31 by savincen          #+#    #+#             */
/*   Updated: 2017/05/24 16:28:52 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
int		parse_camera(int fd, t_obj *obj)
{
	char	*line;

	obj->obj_type = CAMERA;
	set_null(obj);
	while (get_next_line(fd, &line) == 1 && check_type(line) != LINE)
	{
		if (check_type(line) == SPACE || check_type(line) == PARAMETER)
			read_line(line, obj);
		obj->dir->x = 0;
		obj->dir->y = 0;
		obj->dir->z = 1;
		if (check_type(line) == DELIMITER)
			return (2);
		else if (check_type(line) == TITLE)
			ft_syntax_error(line, 1);
		free(line);
	}
	free(line);
	return (1);
}

int		parse_light(int fd, t_obj *obj)
{
	char	*line;

	obj->obj_type = LIGHT;
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

int		parse_sphere(int fd, t_obj *obj)
{
	char	*line;

	obj->obj_type = SPHERE;
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

int		parse_cone(int fd, t_obj *obj)
{
	char	*line;

	obj->obj_type = CONE;
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
	obj->r = tan(obj->r * (M_PI / 180));
	free(line);
	return (1);
}
