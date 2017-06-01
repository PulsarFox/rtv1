/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:53:52 by savincen          #+#    #+#             */
/*   Updated: 2017/03/27 19:50:46 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "keys.h"
#include <stdlib.h>

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == ESCAPE)
		exit(1);
	return (0);
}
