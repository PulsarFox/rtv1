/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:41:26 by savincen          #+#    #+#             */
/*   Updated: 2017/04/13 20:06:13 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include <stdio.h>
#include "libft.h"

void		pos_calc(int x, int y, t_calc *v, t_obj *cam)
{
	double	norm;

	v->pixx = v->pix_origin_x + (1 * v->xind * x) -
		(0 * v->yind * y);
	v->pixy = v->pix_origin_y + (0 * v->xind * x) -
		(1 * v->yind * y);
	v->pixz = v->pix_origin_z + (0 * v->xind * x) -
		(0 * v->yind * y);
	v->dirx = v->pixx - cam->x;
	v->diry = v->pixy - cam->y;
	v->dirz = v->pixz - cam->z;
	norm = 1 / sqrt(pow(v->dirx, 2) + pow(v->diry, 2) + pow(v->dirz, 2));
	cam->dir[0] = v->dirx * norm;
	cam->dir[1] = v->diry * norm;
	cam->dir[2] = v->dirz * norm;
}

void	init_pos(t_env *e, t_obj *cam, t_calc *v)
{
	v->v_pWidth = 0.5;
	v->v_pHeight = ((double)e->height * v->v_pWidth) / (double)e->width;
	v->v_pDist = 0.5;
	v->pix_origin_x = cam->x + ((cam->dir[0] * v->v_pDist)
			+ (0 * (v->v_pHeight / 2.0)))
				- (1 * (v->v_pWidth / 2.0));
	v->pix_origin_y = cam->y + ((cam->dir[1] * v->v_pDist)
			+ (1 * (v->v_pHeight / 2.0)))
				- (0 * (v->v_pWidth / 2.0));
	v->pix_origin_z = cam->z + ((cam->dir[2] * v->v_pDist)
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

static t_obj	*get_light(t_obj *obj)
{
	t_obj *light;

	light = obj;
	while (light)
	{
		if (light->obj_type == LIGHT)
		{
			light->color[0] = 1;
			light->color[1] = 1;
			light->color[2] = 1;
			break;
		}
		light = light->next;
	}
	return (light);
}

void	raytracer(t_env *e, t_calc *v, t_obj *obj)
{
	int		x;
	int		y;
	int		index;
	t_obj	*light;
	t_obj	*cam;

	y = 0;
	cam = get_camera(obj, e, v);
	light = get_light(obj);
	while (y < e->height)
	{
		x = 0;
		while (x < e->width)
		{
			v->t = 0;
			pos_calc(x, y, v, cam);
			check_primitives(obj, light, cam, v);
			index = (e->bpp / 8) * x + (y * e->s_l);
			e->data[index] = v->blue;
			e->data[++index] = v->green;
			e->data[++index] = v->red;
			x++;
		}
		y++;
	}
}
