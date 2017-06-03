/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:30:57 by savincen          #+#    #+#             */
/*   Updated: 2017/05/29 19:16:27 by savincen         ###   ########.fr       */
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

static int	verif_nbrarg(char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i] != '\0' && str[i] != '=')
		i++;
	if (i == len)
		ft_syntax_error(str, 0);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	ft_putstr("Invalid input :\n");
	ft_putstr(str);
	ft_putchar('\n');
	exit(1);
}

int		get_nbr(char *str)
{
	int		i;
	char	*ret;
	int		j;
	int		nbr;

	i = 0;
	j = 0;
	verif_nbrarg(str);
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

