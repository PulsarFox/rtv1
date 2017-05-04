/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:40:20 by savincen          #+#    #+#             */
/*   Updated: 2017/04/13 20:07:49 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rtv1.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	t_obj *obj;
	t_obj *tmp;

	if (argc != 2)
		ft_args_error("", 0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_args_error(argv[1], 1);
	parser(fd, &obj);
	tmp = obj;
	while (obj)
	{
		printf("%s\n", obj->name);
		obj = obj->next;
	}
	free_list_obj(tmp);
	while (1);
	return (0);
}
