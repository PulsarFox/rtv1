/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_primitive_list_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:16:12 by savincen          #+#    #+#             */
/*   Updated: 2017/05/24 16:25:54 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
void	set_null(t_obj *obj)
{
	obj->pos = (t_vect *)malloc(sizeof(t_vect));
	obj->pos->x = 0;
	obj->pos->y = 0;
	obj->pos->z = 0;
	obj->index = 0;
	obj->r = 1;
	obj->name = NULL;
	obj->dir = (t_vect *)malloc(sizeof(t_vect));
	obj->dir->x = 0;
	obj->dir->y = 0;
	obj->dir->z = 1;
	obj->color = (t_vect *)malloc(sizeof(t_vect));
	obj->color->x = 255;
	obj->color->y = 255;
	obj->color->z = 255;
	obj->rot = (t_vect *)malloc(sizeof(t_vect));
	obj->rot->x = 0;
	obj->rot->y = 0;
	obj->rot->z = 0;
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

