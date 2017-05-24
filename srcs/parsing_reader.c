/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:40:49 by savincen          #+#    #+#             */
/*   Updated: 2017/05/24 18:04:43 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	free_conf(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
}

int		valid_line(char *str, char c1, char c2)
{
	int		i;
	int		index;
	int		j;
	int		kezack;

	i = 0;
	index = 0;
	j = 0;
	kezack = 0;
	if (c1 == c2)
		kezack = 1;
	while (str[i] != '\0')
	{
		if (str[i] == c1)
			index++;
		if (str[i] == c2)
			j++;
		i++;
	}
	if ((index == 0 || j == 0) || (kezack == 1 && index % 2 != 0))
		ft_syntax_error(str, 0);
	if ((index != j || index >= 2 || j >= 2) && kezack == 0)
		ft_syntax_error(str, 0);
	return (1);
}

static void		read_line_two(char *line, t_obj *obj)
{
	char	**conf;
	char	*name;

	if (ft_strstr(line, "rotation"))
	{
		valid_line(line, '(', ')');
		conf = get_conf(line, '(', ')');
		obj->rot.x = ft_atoi(conf[0]);
		obj->rot.y = ft_atoi(conf[1]);
		obj->rot.z = ft_atoi(conf[2]);
		free_conf(conf);
		free(conf);
	}
	else if (ft_strstr(line, "direction"))
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
		obj->pos.x = obj->pos.x + ft_atoi(conf[0]);
		obj->pos.y = obj->pos.y + ft_atoi(conf[1]);
		obj->pos.z = obj->pos.z + ft_atoi(conf[2]);
		free_conf(conf);
		free(conf);
	}
}

void	read_line(char *line, t_obj *obj)
{
	char		**conf;

	conf = NULL;
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
	else if (ft_strstr(line, "rayon"))
		obj->r = get_nbr(line);
	else
	{
		read_line_two(line, obj);
		read_line_three(line, obj, conf);
	}
}
