/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:46:48 by savincen          #+#    #+#             */
/*   Updated: 2016/12/12 18:49:57 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_words(char const *s, char c)
{
	size_t	i;
	int		indice;

	i = 0;
	indice = 0;
	while (*s != '\0')
	{
		if (indice == 1 && *s == c)
			indice = 0;
		if (indice == 0 && *s != c)
		{
			i++;
			indice = 1;
		}
		s++;
	}
	return (i);
}
