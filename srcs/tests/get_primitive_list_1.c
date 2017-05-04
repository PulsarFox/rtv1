/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_primitive_list_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:47:31 by savincen          #+#    #+#             */
/*   Updated: 2017/04/13 19:17:12 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <stdlib.h>

int		parse_camera(int fd, t_obj *obj)
{
	char	*line;
	int		delim;

	delim = 0;
	obj->obj_type = CAMERA;
	while (get_next_line(fd, &line) == 1 && check_type(line) != LINE)
	{
		if (check_type(line) == SPACE || check_type(line) == PARAMETER)
			read_line(line, obj);
		else if (check_type(line) == DELIMITER)
			return (2); //FIN DE FICHIER
		else if (check_type(line) == LINE)
			delim++;
		free(line);
	}
	if (delim == 0)
		return (ERROR);
	return (1);
}

int		parse_light(int fd, t_obj *obj)
{
	char	*line;
	int		delim;

	delim = 0;
	obj->obj_type = LIGHT;
	while (get_next_line(fd, &line) == 1 && check_type(line) != LINE)
	{
		if (check_type(line) == SPACE || check_type(line) == PARAMETER)
			read_line(line, obj);
		else if (check_type(line) == DELIMITER)
			return (2); //FIN DE FICHIER
		else if (check_type(line) == LINE)
			delim++;
		free(line);
	}
	if (delim == 0)
		return (ERROR);
	return (1);
}

int		parse_sphere(int fd, t_obj *obj)
{
	char	*line;
	int		delim;

	delim = 0;
	obj->obj_type = SPHERE;
	while (get_next_line(fd, &line) == 1 && check_type(line) != LINE)
	{
		if (check_type(line) == SPACE || check_type(line) == PARAMETER)
			read_line(line, obj);
		else if (check_type(line) == DELIMITER)
			return (2); //FIN DE FICHIER
		else if (check_type(line) == LINE)
			delim++;
		free(line);
	}
	if (delim == 0)
		return (ERROR);
	return (1);
}

int		parse_plan(int fd, t_obj *obj)
{
	char	*line;
	int		delim;

	delim = 0;
	obj->obj_type = PLAN;
	while (get_next_line(fd, &line) == 1 && check_type(line) != LINE)
	{
		if (check_type(line) == SPACE || check_type(line) == PARAMETER)
			read_line(line, obj);
		else if (check_type(line) == DELIMITER)
			return (2); //FIN DE FICHIER
		else if (check_type(line) == LINE)
			delim++;
		free(line);
	}
	if (delim == 0)
		return (ERROR);
	return (1);
}

int		parse_cone(int fd, t_obj *obj)
{
	char	*line;
	int		delim;

	delim = 0;
	obj->obj_type = CONE;
	while (get_next_line(fd, &line) == 1 && check_type(line) != LINE)
	{
		if (check_type(line) == SPACE || check_type(line) == PARAMETER)
			read_line(line, obj);
		else if (check_type(line) == DELIMITER)
			return (2); //FIN DE FICHIER
		else if (check_type(line) == LINE)
			delim++;
		free(line);
	}
	if (delim == 0)
		return (ERROR);
	return (1);
}
