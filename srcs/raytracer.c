/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:41:26 by savincen          #+#    #+#             */
/*   Updated: 2017/05/09 13:51:13 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include <stdio.h>
#include "libft.h"

void		pos_calc(int x, int y, t_calc *v, t_obj *cam)
{
	double	norm;
	t_vect	tmp;

	v->pix.x = v->pix_origin.x + (1 * v->xind * x) -
		(0 * v->yind * y);
	v->pix.y = v->pix_origin.y + (0 * v->xind * x) -
		(1 * v->yind * y);
	v->pix.z = v->pix_origin.z + (0 * v->xind * x) -
		(0 * v->yind * y);
	tmp.x = v->pix.x - cam->pos->x;
	tmp.y = v->pix.y - cam->pos->y;
	tmp.z = v->pix.z - cam->pos->z;
	norm = 1 / sqrt(dot_product(&tmp, &tmp));
	cam->dir->x = tmp.x * norm;
	cam->dir->y = tmp.y * norm;
	cam->dir->z = tmp.z * norm;
}

void	init_pos(t_env *e, t_obj *cam, t_calc *v)
{
	v->v_pWidth = 0.5;
	v->v_pHeight = ((double)e->height * v->v_pWidth) / (double)e->width;
	v->v_pDist = 0.5;
	v->pix_origin.x = cam->pos->x + ((cam->dir->x * v->v_pDist)
			+ (0 * (v->v_pHeight / 2.0)))
				- (1 * (v->v_pWidth / 2.0));
	v->pix_origin.y = cam->pos->y + ((cam->dir->y * v->v_pDist)
			+ (1 * (v->v_pHeight / 2.0)))
				- (0 * (v->v_pWidth / 2.0));
	v->pix_origin.z = cam->pos->z + ((cam->dir->z * v->v_pDist)
			+ (0 * (v->v_pHeight / 2.0)))
				- (0 * (v->v_pWidth / 2.0));
	v->xind = (v->v_pWidth / (double)e->width);
	v->yind = (v->v_pHeight / (double)e->height);
}

static t_obj	*get_camera(t_obj *obj, t_env *e, t_calc *v)
{
	t_obj	*cam;

	cam = obj;
	while (cam)
	{
		if (cam->obj_type == CAMERA)
			break;
		cam = cam->next;
	}
	init_pos(e, cam, v);
	return (cam);
}


void	raytracer(t_env *e, t_calc *v, t_obj *obj)
{
	int		x;
	int		y;
	int		index;
	t_obj	*cam;

	y = 0;
	cam = get_camera(obj, e, v);
	while (y < e->height)
	{
		x = 0;
		while (x < e->width)
		{
			v->t = 0;
			pos_calc(x, y, v, cam);
			check_primitives(obj, cam, v);
			index = (e->bpp / 8) * x + (y * e->s_l);
			e->data[index] = v->blue;
			e->data[++index] = v->green;
			e->data[++index] = v->red;
			x++;
		}
		y++;
	}
}
