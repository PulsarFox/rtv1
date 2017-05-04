/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:30:57 by savincen          #+#    #+#             */
/*   Updated: 2017/04/13 19:52:52 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <stdlib.h>


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
		return (NULL);
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
	return (ret);
}

char	**get_conf(char *line, char c1, char c2)
{
	char	**conf;
	char	*str;

	str = get_between_cs(line, c1, c2);
	conf = ft_strsplit(str, ',');
	free(str);
	return (conf);
}

void		get_dir_type(char *line, int i, t_obj *obj)
{
	if (ft_strchrword(line, "DEFAULT", i))
	{
		obj->dir[0] = 0;
		obj->dir[1] = 0;
		obj->dir[2] = 1;
	}
	else if (ft_strchrword(line, "VERTICAL", i))
	{
		obj->dir[0] = 0;
		obj->dir[1] = 0;
		obj->dir[2] = 1;
	}
	else if (ft_strchrword(line, "HORIZONTAL", i))
	{
		obj->dir[0] = 0;
		obj->dir[1] = 1;
		obj->dir[2] = 0;
	}
	else if (ft_strchrword(line, "RVERTICAL", i))
	{
		obj->dir[0] = 1;
		obj->dir[1] = 0;
		obj->dir[2] = 0;
	}
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

