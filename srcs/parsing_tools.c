/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:30:57 by savincen          #+#    #+#             */
/*   Updated: 2017/05/24 19:18:23 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*get_between_cs(char *str, char c1, char c2)
{
	int		i;
	char	*ret;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != c1)
		i++;
	if ((size_t)i == ft_strlen(str))
		ft_syntax_error(str, 0);
	while (str[i++] != '\0' && str[i] != c2)
		j++;
	i = i - j;
	ret = (char *)malloc(sizeof(char) * j + 1);
	j = 0;
	while (str[i] != c2)
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	**get_conf(char *line, char c1, char c2)
{
	char	**conf;
	char	*str;

	str = get_between_cs(line, c1, c2);
	if (str[0] == '\0')
	{
		ft_putstr("Invalid argument at line :\n");
		ft_putstr(line);
		ft_putchar('\n');
		exit(1);
	}
	conf = ft_strsplit(str, ',');
	if (conf[0] == '\0' || conf[1] == '\0' || conf[2] == '\0' ||
			conf[3] != NULL)
	{
		ft_putstr("Invalid argument at line :\n");
		ft_putstr(line);
		ft_putchar('\n');
		exit(1);
	}
	free(str);
	return (conf);
}

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
		ft_putstr("Invalid direction at line\n");
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

int		get_nbr(char *str)
{
	int		i;
	char	*ret;
	int		j;
	int		nbr;

	i = 0;
	j = 0;
	while (str[i] != '\0' && !ft_isdigit(str[i]))
		i++;
	while (str[i++] != '\0' && ft_isdigit(str[i]))
		j++;
	i = i - j - 1;
	ret = (char *)malloc(sizeof(char) * j + 1);
	j = 0;
	while (ft_isdigit(str[i]))
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	nbr = ft_atoi(ret);
	free(ret);
	return (nbr);
}

