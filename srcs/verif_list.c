/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:13:07 by savincen          #+#    #+#             */
/*   Updated: 2017/06/06 15:03:18 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

void	verif_standarts(t_obj **obj)
{
	t_obj	*tmp;
	int		camcount;
	int		lightcount;
	int		objcount;

	tmp = *obj;
	camcount = 0;
	lightcount = 0;
	objcount = 0;
	while (tmp)
	{
		if (tmp->obj_type == CAMERA)
			camcount++;
		else if (tmp->obj_type == LIGHT)
			lightcount++;
		else if (tmp->obj_type)
			objcount++;
		tmp = tmp->next;
	}
	if (camcount != 1)
		ft_file_error(CAMERA);
	if (lightcount == 0)
		ft_file_error(LIGHT);
	if (objcount == 0)
		ft_file_error(2);
}

void	verif_args(t_obj *lstobj)
{
	t_obj *obj;

	obj = lstobj;
	while (obj)
	{
		if (obj->color.x > 255 || obj->color.x < 0 || obj->color.y > 255 ||
				obj->color.y < 0 || obj->color.z > 255 || obj->color.z < 0)
		{
			ft_putstr("Color value must be between 0 and 255\n");
			exit(1);
		}
		if (obj->rot.x > 360 || obj->rot.x < -360 || obj->rot.y > 360 ||
				obj->rot.y < -360 || obj->rot.z > 360 || obj->rot.z < -360)
		{
			ft_putstr("Rotation value must be between -360 and 360\n");
			exit(1);
		}
		obj = obj->next;
	}
}
