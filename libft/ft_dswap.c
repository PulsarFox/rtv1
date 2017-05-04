#include "libft.h"

void	ft_dswap(double *var1, double *var2)
{
	double	tmp;

	tmp = *var1;
	*var1 = *var2;
	*var2 = tmp;
}
