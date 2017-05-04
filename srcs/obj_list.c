/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:38:55 by savincen          #+#    #+#             */
/*   Updated: 2017/04/05 16:04:26 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <stdio.h>

void		load_attributes(char **tab, t_obj *new)
{
	new->x = ft_atoi(tab[1]);
	new->y = ft_atoi(tab[2]);
	new->z = ft_atoi(tab[3]);
	new->obj_type = ft_atoi(tab[0]);
	new->r = ft_atoi(tab[4]);
	new->dir[0] = ft_atoi(tab[5]);
	new->dir[1] = ft_atoi(tab[6]);
	new->dir[2] = ft_atoi(tab[7]);
}

void	newobj(char *str, t_obj *obj)
{
	t_obj *tmp;
	char	**tab;

	if (obj == NULL)
		obj = (t_obj *)malloc(sizeof(t_obj));
	if (obj == NULL)
		return (NULL);
	if (str == NULL)
		return (NULL);
	tmp = obj;
	tab = ft_strsplit(str, ',');
	load_attributes(tab, obj);
	obj->next = NULL;
	return (new);
}

void	objadd(t_obj **lsobj, t_obj *new)
{
	if (new != NULL && lsobj != NULL)
	{
		new->next = *lsobj;
		*lsobj = new;
	}
}

t_obj	*testobj(void)
{
	t_obj *obj;
	char	*sphere1 = "1, 10, 20, 200, 20, 0, 0, 0";
	char	*plan1 = "2, 0, 0, 0, 0, 0, 1, 0";
	char	*sphere2 = "1, 0, 50, 99, 10, 0, 0, 0";
	char	*plan = "2, 0, 0, 500, 0, 0, 0, 1";

	newobj(sphere1, obj);
	newobj(plan1, obj);
	newobj(sphere2, obj);
	newobj(plan, obj);
	return (obj);
}
