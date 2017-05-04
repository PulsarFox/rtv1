/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:40:26 by savincen          #+#    #+#             */
/*   Updated: 2015/12/07 12:50:11 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	a;

	i = 0;
	s1 = (unsigned char*)dest;
	s2 = (unsigned char*)src;
	a = (unsigned char)c;
	while (i < n)
	{
		if ((*s1++ = *s2++) == a)
			return (s1);
		i++;
	}
	return (NULL);
}
