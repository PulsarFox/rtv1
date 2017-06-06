/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_primitive_list_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:47:31 by savincen          #+#    #+#             */
/*   Updated: 2017/06/06 14:45:03 by savincen         ###   ########.fr       */
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
	int		k;

	k = 0;
	obj->obj_type = CAMERA;
	set_null(obj);
	while (get_next_line(fd, &line) == 1 && check_type(line) != LINE)
	{
		if (check_type(line) == PARAMETER)
			k = k + read_line(line, obj);
		else if (check_type(line) == TITLE)
			ft_syntax_error(line, 1);
		free(line);
	}
	if (check_type(line) == DELIMITER)
		return (2);
	if (k == 0)
	{
		ft_putstr("A camera direction point must be given\n");
		exit(1);
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
		if (check_type(line) == PARAMETER)
			read_line(line, obj);
		else if (check_type(line) == DELIMITER)
			return (2);
		else if (check_type(line) == TITLE)
			ft_syntax_error(line, 1);
		free(line);
	}
	if (obj->r > 10 || obj->r < 0)
	{
		ft_putstr("The intensity value must be between 0 and 10\n");
		exit(1);
	}
	obj->color.x = (obj->color.x * (obj->r / 10)) / 255;
	obj->color.y = (obj->color.y * (obj->r / 10)) / 255;
	obj->color.z = (obj->color.z * (obj->r / 10)) / 255;
	free(line);
	return (1);
}


