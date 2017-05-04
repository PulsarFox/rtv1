/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:40:49 by savincen          #+#    #+#             */
/*   Updated: 2017/04/13 19:53:21 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <stdlib.h>

static void		read_line_two(char *line, t_obj *obj, int i)
{
	char	**conf;
	char	*name;

	if (ft_strchrword(line, "rotation", i))
	{
		conf = get_conf(line, '(', ')');
		obj->rot[0] = ft_atoi(conf[0]);
		obj->rot[1] = ft_atoi(conf[1]);
		obj->rot[2] = ft_atoi(conf[2]);
	}
	else if (ft_strchrword(line, "direction", i))
		get_dir_type(line, i, obj);
	else if (ft_strchrword(line, "name", i))
	{
		name = get_between_cs(line, '"', '"');
		obj->name = ft_strdup(name);
	}
}

void	read_line(char *line, t_obj *obj)
{
	int		i;
	char		**conf;

	i = 0;
	while (line[i] == '	')
		i++;
	if (ft_strchrword(line, "position", i))
	{
		conf = get_conf(line, '(', ')');
		obj->x = ft_atoi(conf[0]);
		obj->y = ft_atoi(conf[1]);
		obj->z = ft_atoi(conf[2]);
	}
	else if (ft_strchrword(line, "color", i))
	{
		conf = get_conf(line, '(', ')');
		obj->color[0] = ft_atoi(conf[0]);
		obj->color[1] = ft_atoi(conf[1]);
		obj->color[2] = ft_atoi(conf[2]);
	}
	else if (ft_strchrword(line, "rayon", i))
		obj->r = get_nbr(line);
	else
		read_line_two(line, obj, i);
}
