/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:20:49 by savincen          #+#    #+#             */
/*   Updated: 2017/05/30 16:26:14 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rtv1.h"

static double		vect_len(t_vect a)
{
	double	len;

	len = sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
	return (len);
}

double		pos_diff(t_vect a, t_vect b)
{
	double	angle;

	angle = acos(dot_product(a, b) / (vect_len(a) * vect_len(b)));
	return (angle);
}

t_vect		rot_camx(t_vect a, t_vect b)
{
	double	k;
	t_vect	ret;

	k = pos_diff(a, b);
	ret.x = a.x;
	ret.y = sin(k);
	ret.z = -cos(k);
	return (ret);
}

t_vect		rot_camy(t_vect a, t_vect b)
{
	double	k;
	t_vect	ret;

	k = pos_diff(a, b);
	ret.x = sin(k);
	ret.y = a.y;
	ret.z = -cos(k);
	return (ret);
}

t_vect		vect_mult(t_vect a, t_vect b)
{
	t_vect	ret;

	ret.x = (a.y * b.z) - (a.z * b.y);
	ret.y = (a.z * b.x) - (a.x * b.z);
	ret.z = (a.x * b.y) - (a.y * b.x);
	return (ret);
}
