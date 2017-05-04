/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:34:28 by savincen          #+#    #+#             */
/*   Updated: 2017/04/13 19:54:33 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rtv1.h"
#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
t_env	*init_env(void)
{
	t_env	*e;

	if ((e = (t_env*)malloc(sizeof(t_env))) == NULL)
		ft_malloc_error();
	e->height = 600;
	e->width = 800;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "rtv1");
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->s_l, &e->endian);
	return (e);
}


int		main(int argc, char **argv)
{
	t_env	*e;
	t_calc		*calc;
	t_obj	*obj;
	t_obj	*tmp;
	int		fd;

	(void)argv;
	if (argc != 2)
		ft_args_error("", 0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_args_error(argv[1], 1);
	if ((calc = (t_calc*)malloc(sizeof(t_calc))) == NULL)
		return (0);
	parser(fd, &obj);
	tmp = obj;
	e = init_env();
	while (tmp)
	{
		printf("coord = %d, %d, %d. type = %d. r = %d, dir = %f, %f, %f, color = %f, %f, %f\n", tmp->x, tmp->y, tmp->z, tmp->obj_type, tmp->r, tmp->dir[0], tmp->dir[1], tmp->dir[2], tmp->color[0], tmp->color[1], tmp->color[2]);
		tmp = tmp->next;
	}
	raytracer(e, calc, obj);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
	free_list_obj(obj);
}
