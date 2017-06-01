/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:41:26 by savincen          #+#    #+#             */
/*   Updated: 2017/05/30 16:45:11 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>
#include <stdio.h>
#include "libft.h"

static void		pos_calc(int x, int y, t_calc *v, t_obj *cam)
{
	double	norm;
	t_vect	tmp;

	v->pix.x = v->pix_origin.x + (v->right.x * v->xind * (double)x) -
		(v->up.x * v->yind * (double)y);
	v->pix.y = v->pix_origin.y + (v->right.y * v->xind * (double)x) -
		(v->up.y * v->yind * (double)y);
	v->pix.z = v->pix_origin.z + (v->right.z * v->xind * (double)x) -
		(v->up.z * v->yind * (double)y);
	tmp.x = v->pix.x - cam->pos.x;
	tmp.y = v->pix.y - cam->pos.y;
	tmp.z = v->pix.z - cam->pos.z;
	norm = 1 / sqrt(dot_product(tmp, tmp));
	cam->dir.x = tmp.x * norm;
	cam->dir.y = tmp.y * norm;
	cam->dir.z = tmp.z * norm;
}

static void		init_pos(t_env *e, t_obj *cam, t_calc *v)
{
	t_vect	dir;

	dir = rotation(cam->dir, cam->rot);
	v->right = new_vect(1, 0, 0);
	v->right = rotation(v->right, cam->rot);
	v->up = new_vect(0, 1, 0);
	v->up = rotation(v->up, cam->rot);
	v->v_pWidth = 0.5;
	v->v_pHeight = ((double)e->height * v->v_pWidth) / (double)e->width;
	v->v_pDist = 0.5;
	v->pix_origin.x = cam->pos.x + ((dir.x * v->v_pDist)
			+ (v->up.x * (v->v_pHeight / 2.0)))
				- (v->right.x * (v->v_pWidth / 2.0));
	v->pix_origin.y = cam->pos.y + ((dir.y * v->v_pDist)
			+ (v->up.y * (v->v_pHeight / 2.0)))
				- (v->right.y * (v->v_pWidth / 2.0));
	v->pix_origin.z = cam->pos.z + ((dir.z * v->v_pDist)
			+ (v->up.z * (v->v_pHeight / 2.0)))
				- (v->right.z * (v->v_pWidth / 2.0));
	v->xind = (v->v_pWidth / (double)e->width);
	v->yind = (v->v_pHeight / (double)e->height);
}

static t_obj	*get_camera(t_obj *obj, t_env *e, t_calc *v)
{
	t_obj	*cam;
	int		i;

	i = 0;
	cam = obj;
	while (cam)
	{
		if (cam->obj_type == CAMERA)
			break;
		i++;
		cam = cam->next;
	}
	if (i != 0)
		ft_file_error(CAMERA);
	init_pos(e, cam, v);
	return (cam);
}

static	void	init_plan_normal(t_obj **obj)
{
	t_obj	*tmp;

	tmp = *obj;
	while (tmp)
	{
		if (tmp->obj_type == PLAN)
			tmp->dir = calc_plan_norm(tmp);
		tmp = tmp->next;
	}
}

void	raytracer(t_env *e, t_calc *v, t_obj *obj)
{
	int		x;
	int		y;
	int		index;
	t_obj	*cam;

	y = 0;
	cam = get_camera(obj, e, v);
	init_plan_normal(&obj);
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
