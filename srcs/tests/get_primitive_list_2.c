/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_primitive_list_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:16:12 by savincen          #+#    #+#             */
/*   Updated: 2017/04/13 19:17:07 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <stdlib.h>

int		parse_cylinder(int fd, t_obj *obj)
{
	char	*line;
	int		delim;

	delim = 0;
	obj->obj_type = CYLINDER;
	while (get_next_line(fd, &line) == 1 && check_type(line) != LINE)
	{
		if (check_type(line) == SPACE || check_type(line) == PARAMETER)
			read_line(line, obj);
		else if (check_type(line) == DELIMITER)
			return (2); //FIN DE FICHIER
		else if (check_type(line) == LINE)
			delim++;
		free(line);
	}
	if (delim == 0)
		return (ERROR);
	return (1);
}

