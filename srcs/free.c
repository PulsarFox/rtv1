#include <stdlib.h>
#include "rtv1.h"

void	free_conf(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
}

void	free_list_obj(t_obj *obj)
{
	t_obj	*tmp;

	while (obj)
	{
		tmp = obj->next;
		if (obj)
		{
			free(obj->name);
			free(obj);
		}
		obj = tmp;
	}
}


