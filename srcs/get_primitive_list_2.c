/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_primitive_list_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:16:12 by savincen          #+#    #+#             */
/*   Updated: 2017/04/13 19:17:07 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
void	set_null(t_obj *obj)
{
	obj->x = 0;
	obj->y = 0;
	obj->z = 0;
	obj->index = 0;
	obj->r = 0;
	obj->name = NULL;
	obj->dir[0] = 0;
	obj->dir[1] = 0;
	obj->dir[2] = 1;
	obj->color[0] = 255;
	obj->color[1] = 255;
	obj->color[2] = 255;
	obj->rot[0] = 0;
	obj->rot[1] = 0;
	obj->rot[2] = 0;
	obj->next = NULL;
}

void	free_list_obj(t_obj *obj)
{
	t_obj	*tmp;

	while (obj)
	{
		tmp = obj->next;
		if (obj)
		{
			free(obj->name);
			free(obj);
		}
		obj = tmp;
	}
}

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

