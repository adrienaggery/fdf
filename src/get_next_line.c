/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 21:33:43 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/23 15:46:13 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fd_link	*find_save(int fd, t_fd_link *fd_list)
{
	while (fd_list)
	{
		if (fd_list->fd == fd)
			return (fd_list);
		else
			fd_list = fd_list->next;
	}
	return (NULL);
}

static int			write_to_save(int fd, t_fd_link **fd_list,
		char *buffer, size_t size)
{
	t_fd_link		*elt;
	char			*tofree;

	elt = find_save(fd, *fd_list);
	if (elt == NULL)
	{
		elt = (t_fd_link *)malloc(sizeof(t_fd_link));
		if (elt == NULL)
			return (1);
		elt->fd = fd;
		elt->o_b_s = 0;
		elt->o_b = NULL;
		elt->next = *fd_list;
		*fd_list = elt;
	}
	tofree = elt->o_b;
	elt->o_b = ft_memjoin(elt->o_b, elt->o_b_s, buffer, size);
	free(tofree);
	elt->o_b_s += size;
	return (0);
}

static char			*read_from_save(t_fd_link *link, int force_ret)
{
	int				i;
	char			*r;
	char			*tofree;

	if (link == NULL)
		return (NULL);
	i = -1;
	while (++i < link->o_b_s)
		if (link->o_b[i] == '\n')
		{
			r = ft_strsub(link->o_b, 0, i);
			tofree = link->o_b;
			link->o_b = ft_strsub(link->o_b, (i + 1), link->o_b_s - (i + 1));
			free(tofree);
			link->o_b_s -= (i + 1);
			return (r);
		}
	if (force_ret)
	{
		r = ft_strsub(link->o_b, 0, link->o_b_s);
		link->o_b = NULL;
		link->o_b_s = 0;
		return (r);
	}
	return (NULL);
}

static int			search_line(int const fd, t_fd_link **fd_list,
		char **line, char *buffer)
{
	int				read_r;

	*line = read_from_save(find_save(fd, *fd_list), 0);
	if (*line == NULL)
	{
		read_r = read(fd, buffer, BUFF_SIZE);
		if (read_r > 0)
		{
			if (!write_to_save(fd, fd_list, buffer, read_r))
				return (search_line(fd, fd_list, line, buffer));
			return (-1);
		}
		else if (read_r == 0)
		{
			if ((*line = read_from_save(find_save(fd, *fd_list), 1)))
				if (*line[0])
					return (1);
			return (0);
		}
		else
			return (-1);
	}
	else
		return (1);
}

int					get_next_line(int const fd, char **line)
{
	static t_fd_link		*fd_list = NULL;
	char					*buffer;
	int						s;

	if (fd == 0 || fd > 2)
	{
		buffer = (char *)malloc(sizeof(char) * BUFF_SIZE);
		if (buffer == NULL)
			return (-1);
		s = search_line(fd, &fd_list, line, buffer);
		if (s == 1)
		{
			free(buffer);
			return (1);
		}
		else if (s == 0)
		{
			free(buffer);
			return (0);
		}
	}
	return (-1);
}
