/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:34:28 by savincen          #+#    #+#             */
/*   Updated: 2017/05/24 16:45:27 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rtv1.h"
#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_env		*e;
	t_calc		*calc;
	t_obj		*obj;
	t_obj		*tmp;
	int			fd;

	if (argc != 2)
		ft_args_error("", 0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_args_error(argv[1], 1);
	if ((calc = (t_calc*)malloc(sizeof(t_calc))) == NULL)
		ft_malloc_error();
	parser(fd, &obj);
	tmp = obj;
	e = init_env();
	while (tmp)
	{
		printf("coord = %f, %f, %f. type = %d. r = %f, dir = %f, %f, %f, color = %f, %f, %f\n", tmp->pos.x, tmp->pos.y, tmp->pos.z, tmp->obj_type, tmp->r, tmp->dir.x, tmp->dir.y, tmp->dir.z, tmp->color.x, tmp->color.y, tmp->color.z);
		tmp = tmp->next;
	}
	raytracer(e, calc, obj);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
	free_list_obj(obj);
}
