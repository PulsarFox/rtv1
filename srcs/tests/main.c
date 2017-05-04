/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:40:20 by savincen          #+#    #+#             */
/*   Updated: 2017/04/13 19:43:33 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include "rtv1.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	t_obj *obj;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	parser(fd, &obj);
	return (0);
}
