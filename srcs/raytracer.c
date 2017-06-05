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
	t_vect	tmp;

	v->pix.x = v->pix_origin.x + (v->right.x * v->xind * (double)x) -
		(v->up.x * v->yind * (double)y);
	v->pix.y = v->pix_origin.y + (v->right.y * v->xind * (double)x) -
		(v->up.y * v->yind * (double)y);
	v->pix.z = v->pix_origin.z + (v->right.z * v->xind * (double)x) -
		(v->up.z * v->yind * (double)y);
	tmp = diff_vect(v->pix, cam->pos);
	cam->dir = normalize(tmp);
}

static	void	init_viewplane(t_env *e, t_obj *cam, t_calc *v, t_vect dir)
{
	v->pix_origin.x = cam->pos.x + ((dir.x * e->v_pDist)
			+ (v->up.x * (e->v_pHeight / 2.0)))
				- (v->right.x * (e->v_pWidth / 2.0));
	v->pix_origin.y = cam->pos.y + ((dir.y * e->v_pDist)
			+ (v->up.y * (e->v_pHeight / 2.0)))
				- (v->right.y * (e->v_pWidth / 2.0));
	v->pix_origin.z = cam->pos.z + ((dir.z * e->v_pDist)
			+ (v->up.z * (e->v_pHeight / 2.0)))
				- (v->right.z * (e->v_pWidth / 2.0));
	v->xind = (e->v_pWidth / (double)e->width);
	v->yind = (e->v_pHeight / (double)e->height);
}

static void		init_pos(t_env *e, t_obj *cam, t_calc *v)
{
	t_vect	dir;
	t_vect	tmp1;
	t_vect	tmp2;

	tmp1 = new_vect(0.0, 1.0, 0.0);
	tmp2 = new_vect(1.0, 0.0, 0.0);
	dir = diff_vect(cam->dir, cam->pos);
	dir = normalize(dir);
	v->right = vect_mult(tmp1, dir);
	if (v->right.x == 0 && v->right.y == 0 && v->right.z == 0)
		v->right.x = 1;
	v->right = normalize(v->right);
	v->up = vect_mult(dir, tmp2);
	if (v->up.x == 0 && v->up.y == 0 && v->up.z == 0)
		v->up.y = 1;
	if (v->right.x < 0.999999 && v->right.x > -0.999999)
		v->up = rot_camx(v->up, dir);
	v->up = normalize(v->up);
	if (v->up.y < -0.00000001)
	{
		v->up.z = -v->up.z;
		v->up.y = -v->up.y;
		v->right = rot_camy(v->right, dir);
		v->right = normalize(v->right);
		v->right.x = -v->right.x;
		v->right.z = -v->right.z;
	}
	init_viewplane(e, cam, v, dir);
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
