#include "rtv1.h"
#include <math.h>
#include <stdlib.h>
#include <mlx.h>

void	set_null(t_obj *obj)
{
	obj->pos.x = 0;
	obj->pos.y = 0;
	obj->pos.z = 0;
	obj->index = 0;
	obj->r = 1;
	obj->name = NULL;
	obj->dir.x = 0;
	obj->dir.y = 0;
	obj->dir.z = 0;
	obj->color.x = 255;
	obj->color.y = 255;
	obj->color.z = 255;
	obj->rot.x = 0;
	obj->rot.y = 0;
	obj->rot.z = 0;
	obj->next = NULL;
	obj->tr.x = 0;
	obj->tr.y = 0;
	obj->tr.z = 0;
}

void	set_translation(t_obj *obj, t_vect vect)
{
	if (vect.x != 0 || vect.y != 0 || vect.z != 0)
	{
		obj->pos.x += vect.x;
		obj->pos.y += vect.y;
		obj->pos.z += vect.z;
	}
}

t_env	*init_env(void)
{
	t_env	*e;

	if ((e = (t_env*)malloc(sizeof(t_env))) == NULL)
		ft_malloc_error();
	e->height = 600;
	e->width = 800;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "rtv1");
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->s_l, &e->endian);
	e->v_pWidth = 0.5;
	e->v_pDist = 0.5;
	e->v_pHeight = ((double)e->height * e->v_pWidth) / (double)e->width;
	return (e);
}

void	init_plan_normal(t_obj **obj)
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


