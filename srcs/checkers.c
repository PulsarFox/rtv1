

#include "rtv1.h"
#include <stdlib.h>
#include "libft.h"

int		same_char_line(char *str, char c)
{
	int		i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int		check_title(char *line)
{
	if (ft_strcmp(line, "LIGHT") == 0 || ft_strcmp(line, "CAMERA") == 0 ||
		ft_strcmp(line, "CYLINDER") == 0 || ft_strcmp(line, "PLAN") == 0 ||
		ft_strcmp(line, "SPHERE") == 0 || ft_strcmp(line, "CONE") == 0)
		return (1);
	else
	{
		ft_putstr("Unknown Object :\n");
		ft_putstr(line);
		ft_putchar('\n');
		exit(1);
	}
	return (0);
}

int		check_parameter(char *line)
{
	if (ft_strstr(line, "type") || ft_strstr(line, "position") ||
		ft_strstr(line, "rotation") || ft_strstr(line, "name") ||
		ft_strstr(line, "translation") || ft_strstr(line, "angle") ||
		ft_strstr(line, "rayon") || ft_strstr(line, "color") ||
		ft_strstr(line, "intensity") || ft_strstr(line, "point_at"))
		return (1);
	else
	{
		ft_putstr("Unknown parameter :\n");
		ft_putstr(line);
		ft_putchar('\n');
		exit(1);
	}
	return (0);
}

int		check_type(char *str)
{
	if (str[0] == '\0' || same_char_line(str, ' ') || same_char_line(str, '	'))
		return (SPACE);
	if (same_char_line(str, '-'))
		return (LINE);
	if (str[0] >= 'A' && str[0] <= 'Z' && check_title(str))
		return (TITLE);
	if (str[0] == '	' && check_parameter(str))
		return (PARAMETER);
	if (str[0] == '#')
		return (COMMENT);
	if (same_char_line(str, '*'))
		return (DELIMITER);
	else
	{
		ft_putstr("Bad syntax at line :\n");
		ft_putstr(str);
		ft_putchar('\n');
		exit(1);
	}
}

int		valid_line(char *str, char c1, char c2)
{
	int		i;
	int		index;
	int		j;
	int		k;

	i = 0;
	index = 0;
	j = 0;
	k = 0;
	if (c1 == c2)
		k = 1;
	while (str[i] != '\0')
	{
		if (str[i] == c1)
			index++;
		if (str[i] == c2)
			j++;
		i++;
	}
	if ((index == 0 || j == 0) || (k == 1 && index % 2 != 0))
		ft_syntax_error(str, 0);
	if ((index != j || index >= 2 || j >= 2) && k == 0)
		ft_syntax_error(str, 0);
	return (1);
}
