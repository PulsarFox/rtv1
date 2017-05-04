/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:37:52 by savincen          #+#    #+#             */
/*   Updated: 2015/12/08 13:11:25 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = dest;
	while (temp[j])
		j++;
	while (src[i] != '\0' && n--)
	{
		temp[j] = src[i];
		j++;
		i++;
	}
	temp[j] = '\0';
	return (dest);
}
