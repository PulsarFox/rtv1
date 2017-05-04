/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:45:15 by savincen          #+#    #+#             */
/*   Updated: 2016/02/08 14:47:47 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int n)
{
	int		ret;

	ret = 0;
	if (n < 0)
	{
		ft_putstr("Error : negative input\n");
		return (0);
	}
	while ((ret * ret) < n)
		ret++;
	return (ret);
}
