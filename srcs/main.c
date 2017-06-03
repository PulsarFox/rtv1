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
	if (argc != 2)
		ft_args_error("", 0);
	printf("same %d\n", same_char_line(argv[1], '*'));
	return (0);
}
