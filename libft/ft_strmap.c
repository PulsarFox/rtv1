/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:25:42 by savincen          #+#    #+#             */
/*   Updated: 2016/11/08 18:41:12 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		str = ft_strnew(ft_strlen(s));
		if (str != NULL)
		{
			while (s[i] != '\0')
			{
				str[i] = f(s[i]);
				i++;
			}
			return (str);
		}
	}
	return (NULL);
}
