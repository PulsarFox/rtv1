/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:48:08 by savincen          #+#    #+#             */
/*   Updated: 2016/11/08 18:40:20 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_blank(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*str;

	str = NULL;
	if (!s)
		return (NULL);
	while (*s && is_blank(*s))
		s++;
	i = ft_strlen(s) - 1;
	if (i > 0)
	{
		while (s[i] && is_blank(s[i]))
			i--;
	}
	str = ft_strsub(s, 0, i + 1);
	return (str);
}
