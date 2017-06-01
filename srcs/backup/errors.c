

#include "rtv1.h"
#include "libft.h"

void	ft_syntax_error(char *line, int i)
{
	if (i == 0)
	{
		ft_putstr("SYNTAX ERROR AT LINE :\n");
		ft_putstr(line);
		ft_putchar('\n');
		ft_putstr("More info at the end of template scene file\n");
		exit(1);
	}
	else
	{
		ft_putstr("MISSING BLOCK DELIMITER : \n");
		ft_putstr(line);
		ft_putchar('\n');
		exit(1);
	}
}

void	ft_delimitor_error(int i)
{
	if (i == 1)
	{
		ft_putstr("THE FILE MUST HAVE A BEGINNING AND ENDING LINE\n");
		ft_putstr("More info at the end of template scene file\n");
		exit(1);
	}
	else if (i == 2)
	{
		ft_putstr("THE FILE MUST HAVE AN ENDING LINE\n");
		ft_putstr("More info at the end of template scene file\n");
		exit(1);
	}
	else
		exit(1);
}

void	ft_malloc_error(void)
{
	ft_putstr("ALLOCATION ERROR\n");
	exit (1);
}

void	ft_args_error(char *str, int i)
{
	if (i != 0)
	{
		ft_putstr("Invalid name : ");
		ft_putstr(str);
		ft_putchar('\n');
	}
	ft_putstr("USAGE : ./rtv1 <filename.sc>\n");
	exit(1);
}

void	ft_file_error(int i)
{
	if (i == CAMERA)
	{
		ft_putstr("THE SCENE MUST HAVE ONE AND ONLY ONE CAMERA\n");
		exit(1);
	}
	else if (i == LIGHT)
	{
		ft_putstr("THE SCENE MUST HAVE AT LEAST ONE LIGHT SOURCE\n");
		exit(1);
	}
	else
	{
		ft_putstr("THE SCENE IS EMPTY\n");
		exit(1);
	}
}
