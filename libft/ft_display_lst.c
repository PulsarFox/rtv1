/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:06:05 by savincen          #+#    #+#             */
/*   Updated: 2016/02/03 17:32:05 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_display_lst(t_list *list)
{
	if (list == NULL)
	{
		ft_putstr("LISTE VIDE\n");
		return ;
	}
	while (list != NULL)
	{
		if (list->content != NULL)
		{
			ft_putstr(list->content);
			ft_putchar(' ');
		}
		list = list->next;
	}
}
