#include "rtv1.h"
#include "libft.h"

void	verif_standarts(t_obj **obj)
{
	t_obj	*tmp;
	int		camcount;
	int		lightcount;
	int		objcount;

	tmp = *obj;
	camcount = 0;
	lightcount = 0;
	objcount = 0;
	while (tmp)
	{
		if (tmp->obj_type == CAMERA)
			camcount++;
		else if (tmp->obj_type == LIGHT)
			lightcount++;
		else if (tmp->obj_type)
			objcount++;
		tmp = tmp->next;
	}
	if (camcount != 1)
		ft_file_error(CAMERA);
	if (lightcount == 0)
		ft_file_error(LIGHT);
	if (objcount == 0)
		ft_file_error(2);
}


