/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savincen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:52:16 by savincen          #+#    #+#             */
/*   Updated: 2016/12/09 16:35:09 by savincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static t_list			*initialize_list(t_list **multi, int const fd)
{
	t_list			*current;
	t_list			*previous;
	t_fd			*data_multfd;

	current = *multi;
	previous = NULL;
	while (current != NULL)
	{
		if (((t_fd*)(current->content))->fd == fd)
			return (current);
		previous = current;
		current = current->next;
	}
	data_multfd = (t_fd*)malloc(sizeof(t_fd));
	data_multfd->stock = ft_strnew(BUFF_SIZE);
	data_multfd->fd = fd;
	current = ft_lstnew(NULL, sizeof(t_list));
	current->content = data_multfd;
	if (previous != NULL)
		previous->next = current;
	else
		*multi = current;
	return (current);
}

static int				check_read(char *buffer, t_list *data, char **line)
{
	char			*tmp;

	if ((tmp = ft_strchr(buffer, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(((t_fd*)(data->content))->stock, buffer);
		free(((t_fd*)(data->content))->stock);
		((t_fd*)(data->content))->stock = ft_strdup(tmp + 1);
		tmp = NULL;
		free(buffer);
		return (1);
	}
	return (0);
}

static int				check_rest(t_list *data, char **line)
{
	char			*tmp;
	char			*tmp2;

	if ((tmp = ft_strchr(((t_fd*)(data->content))->stock, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(((t_fd*)(data->content))->stock);
		tmp2 = ft_strdup(tmp + 1);
		free(((t_fd*)(data->content))->stock);
		((t_fd*)(data->content))->stock = tmp2;
		return (1);
	}
	return (0);
}

static int				read_line(int fd, t_list *data, char **line)
{
	int				ret;
	char			*buf;
	char			*tmp;

	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (check_read(buf, data, line))
			return (1);
		tmp = ft_strjoin(((t_fd*)(data->content))->stock, buf);
		free(((t_fd*)(data->content))->stock);
		((t_fd*)(data->content))->stock = ft_strdup(tmp);
		free(tmp);
	}
	free(buf);
	buf = NULL;
	if (ret == -1)
		return (-1);
	return (0);
}

int						get_next_line(const int fd, char **line)
{
	t_list			*data;
	static t_list	*fdata;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if ((data = initialize_list(&fdata, fd)) == NULL)
		return (-1);
	if (((t_fd*)(data->content))->stock)
		if (check_rest(data, line))
			return (1);
	ret = read_line(fd, data, line);
	if (ret == 1 || ret == -1)
		return (ret);
	if (((t_fd*)(data->content))->stock == NULL ||
			((t_fd*)(data->content))->stock[0] == '\0')
		return (0);
	*line = ft_strdup(((t_fd*)(data->content))->stock);
	free(((t_fd*)(data->content))->stock);
	((t_fd*)(data->content))->stock = NULL;
	return (1);
}
