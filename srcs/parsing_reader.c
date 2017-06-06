/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:40:49 by savincen          #+#    #+#             */
/*   Updated: 2017/06/06 14:16:27 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static int		read_line_four(char *line, t_obj *obj)
{
	char	**conf;

	if (obj->obj_type == CAMERA && ft_strstr(line, "point_at"))
	{
		valid_line(line, '(', ')');
		conf = get_conf(line, '(', ')');
		obj->dir.x = ft_atoi(conf[0]);
		obj->dir.y = ft_atoi(conf[1]);
		obj->dir.z = ft_atoi(conf[2]);
		free_conf(conf);
		free(conf);
		return (1);
	}
	else if (obj->obj_type == LIGHT && ft_strstr(line, "intensity"))
		obj->r = get_nbr(line);
	else if (obj->obj_type == CONE && ft_strstr(line, "angle"))
		obj->r = get_nbr(line);
	return (0);
}

static void		read_line_two(char *line, t_obj *obj)
{
	char	**conf;
	char	*name;

	if (ft_strstr(line, "rotation"))
	{
		valid_line(line, '(', ')');
		conf = get_conf(line, '(', ')');
		obj->rot.x = (ft_atoi(conf[0]) * (M_PI / 180.0));
		obj->rot.y = (ft_atoi(conf[1]) * (M_PI / 180.0));
		obj->rot.z = (ft_atoi(conf[2]) * (M_PI / 180.0));
		free_conf(conf);
		free(conf);
	}
	else if (ft_strstr(line, "type"))
		get_dir_type(line, obj);
	else if (ft_strstr(line, "name"))
	{
		valid_line(line, '"', '"');
		name = get_between_cs(line, '"', '"');
		obj->name = ft_strdup(name);
		free(name);
	}
}

static void		read_line_three(char *line, t_obj *obj, char **conf)
{
	if (ft_strstr(line, "color"))
	{
		valid_line(line, '(', ')');
		conf = get_conf(line, '(', ')');
		obj->color.x = ft_atoi(conf[0]);
		obj->color.y = ft_atoi(conf[1]);
		obj->color.z = ft_atoi(conf[2]);
		free_conf(conf);
		free(conf);
	}
	else if (ft_strstr(line, "translation"))
	{
		valid_line(line, '(', ')');
		conf = get_conf(line, '(', ')');
		obj->tr.x = ft_atoi(conf[0]);
		obj->tr.y = ft_atoi(conf[1]);
		obj->tr.z = ft_atoi(conf[2]);
		free_conf(conf);
		free(conf);
	}
}

int		read_line(char *line, t_obj *obj)
{
	char		**conf;
	int			k;

	conf = NULL;
	k = 0;
	if (ft_strstr(line, "position"))
	{
		valid_line(line, '(', ')');
		conf = get_conf(line, '(', ')');
		obj->pos.x = ft_atoi(conf[0]);
		obj->pos.y = ft_atoi(conf[1]);
		obj->pos.z = ft_atoi(conf[2]);
		free_conf(conf);
		free(conf);
	}
	else if ((obj->obj_type == SPHERE || obj->obj_type == CYLINDER) &&
			ft_strstr(line, "rayon"))
		obj->r = get_nbr(line);
	else
	{
		read_line_two(line, obj);
		read_line_three(line, obj, conf);
		k = read_line_four(line, obj);
	}
	return (k);
}
