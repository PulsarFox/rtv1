/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:52:09 by savincen          #+#    #+#             */
/*   Updated: 2016/02/01 16:48:52 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	a;

	i = 0;
	a = (unsigned char)c;
	ptr = (unsigned char*)s;
	while (i < n)
	{
		if (ptr[i] == a)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
