

#include "rtv1.h"

int		same_char_line(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int		check_type(char *str)
{
	if (same_char_line(str, '-'))
		return (LINE);
	if (same_char_line(str, '*'))
		return (DELIMITER);
	if (str[0] >= 'A' && str[0] <= 'Z')
		return (TITLE);
	if (str[0] == '	')
		return (PARAMETER);
	if (str[0] >= 'a' && str[0] <= 'z')
		return (ERROR);
	if (str[0] == '\0' || same_char_line(str, ' ') || same_char_line(str, '	'))
		return (SPACE);
	return (ERROR);
}


