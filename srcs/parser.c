/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 20:25:05 by savincen          #+#    #+#             */
/*   Updated: 2017/05/24 18:42:57 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rtv1.h"
#include "libft.h"
#include <stdio.h>
t_obj	*newobj(void)
{
	t_obj	*new;

	new = (t_obj *)malloc(sizeof(t_obj));
	if (new == NULL)
		ft_malloc_error();
	return (new);
}

void	objaddend(t_obj **obj, t_obj *new)
{
	t_obj *tmp;

	if (*obj)
	{
		tmp = *obj;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*obj = new;
}

static	void	verif_obj(t_obj *obj)
{
	if ((obj->obj_type == CYLINDER || obj->obj_type == SPHERE) && obj->r <= 0)
	{
		ft_putstr("Rayon must be superior to 0\n");
		exit(1);
	}
	if ((obj->obj_type == PLAN || obj->obj_type == CAMERA) &&
			obj->dir.x == 0 && obj->dir.y == 0 && obj->dir.z == 0)
	{
		ft_putstr("A camera/plan direction is missing\n");
		exit(1);
	}
}

int		parse_objects(char *line, t_obj **obj, int fd, int index)
{
	t_obj	*new;
	int		ret;

	new = newobj();
	ret = 1;
	printf("%d\n", index);
	if (ft_strcmp(line, "CAMERA") == 0)
		ret = parse_camera(fd, new);
	else if (ft_strcmp(line, "LIGHT") == 0)
		ret = parse_light(fd, new);
	else if (ft_strcmp(line, "SPHERE") == 0)
		ret = parse_sphere(fd, new);
	else if (ft_strcmp(line, "PLAN") == 0)
		ret = parse_plan(fd, new);
	else if (ft_strcmp(line, "CONE") == 0)
		ret = parse_cone(fd, new);
	else if (ft_strcmp(line, "CYLINDER") == 0)
		ret = parse_cylinder(fd, new);
	else
		return (1);
	new->index = index;
	verif_obj(new);
	objaddend(obj, new);
	return (ret);
}

void	parser(int fd, t_obj **obj)
{
	char	*line;
	int		endf;
	int		line_type;
	int		index;

	line_type = 0;
	endf = 0;
	index = 0;
	while (get_next_line(fd, &line) == 1)
	{
		line_type = check_type(line);
		if (line_type == DELIMITER)
			endf++;
		if (endf == 0 && line_type != COMMENT)
			ft_delimitor_error(1);
		if (endf == 1 && line_type == TITLE)
		{
			index++;
			endf = parse_objects(line, obj, fd, index);
		}
		if (endf >= 2)
			break;
		free(line);
	}
	if (endf == 0)
		ft_delimitor_error(1);
	free(line);
	verif_standarts(obj);
}
