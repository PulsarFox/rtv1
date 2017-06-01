/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:41:36 by savincen          #+#    #+#             */
/*   Updated: 2017/06/01 18:21:25 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include <stdio.h>

t_vect	rot_z(t_vect vect, double a)
{
	double	tmpx;
	double	tmpy;
	t_vect	ret;

	tmpx = ((vect.x) * cos(a)) + ((vect.y) * -sin(a));
	tmpy = ((vect.x) * sin(a)) + ((vect.y) * cos(a));
	ret.z = vect.z;
	ret.x = tmpx;
	ret.y = tmpy;
	return (ret);
}

t_vect	rot_y(t_vect vect, double a)
{
	double	tmpx;
	double	tmpz;
	t_vect	ret;

	tmpx = ((vect.x) * cos(a)) + ((vect.z) * sin(a));
	tmpz = ((vect.x) * -sin(a)) + ((vect.z) * cos(a));
	ret.x = tmpx;
	ret.y = vect.y;
	ret.z = tmpz;
	return (ret);
}

t_vect	rot_x(t_vect vect, double a)
{
	t_vect ret;
	double	tmpy;
	double	tmpz;

	tmpy = ((vect.y) * cos(a)) + ((vect.z) * -sin(a));
	tmpz = ((vect.y) * sin(a)) + ((vect.z) * cos(a));
	ret.x = vect.x;
	ret.y = tmpy;
	ret.z = tmpz;
	return (ret);
}

t_vect	inv_rotation(t_vect vect, t_vect angle)
{
	t_vect	ret;

	if (
	ret = rot_x(vect, -(angle.x));
	ret = rot_y(ret, -(angle.y));
	ret = rot_z(ret, -(angle.z));
	return (ret);
}

t_vect	rotation(t_vect vect, t_vect angle)
{
	t_vect	ret;

	ret = rot_x(vect, angle.x);
	ret = rot_y(ret, angle.y);
	ret = rot_z(ret, angle.z);
	return (ret);
}
