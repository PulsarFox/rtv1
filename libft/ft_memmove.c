/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:44:35 by savincen          #+#    #+#             */
/*   Updated: 2016/02/04 14:16:48 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*c;
	unsigned char	*k;

	c = (unsigned char*)dest;
	k = (unsigned char*)src;
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (n > 0)
	{
		c[n - 1] = k[n - 1];
		n--;
	}
	return (c);
}
