/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 10:35:53 by aaggery           #+#    #+#             */
/*   Updated: 2015/01/17 17:52:29 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		*ft_itop(int p)
{
	int		*i;

	i = (int *)malloc(sizeof(int));
	if (i == NULL)
	{
		ft_putendl_fd("Error, malloc returned NULL.", 2);
		exit(EXIT_FAILURE);
	}
	*i = p;
	return (i);
}

static int		ft_get_row_count(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		free(line);
		i++;
	}
	return (i);
}

static int		**ft_aatoai(char **aa)
{
	int			**ai;
	size_t		i;
	size_t		j;

	i = 0;
	while (aa[i])
		i++;
	ai = (int **)malloc(sizeof(int *) * (i + 1));
	if (ai == NULL)
	{
		ft_putendl_fd("Error, malloc returned NULL.", 2);
		exit(EXIT_FAILURE);
	}
	j = 0;
	while (aa[j])
	{
		ai[j] = ft_itop(ft_atoi(aa[j]));
		j++;
	}
	ai[j] = NULL;
	return (ai);
}

int				***ft_load_map(char *file)
{
	int		***map;
	char	*line;
	char	**splitted_line;
	int		fd;
	size_t	i;

	map = (int ***)malloc(sizeof(int **) * (ft_get_row_count(file) + 1));
	if (map == NULL)
	{
		ft_putendl_fd("Error, malloc returned NULL.", 2);
	}
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		splitted_line = ft_strsplit(line, ' ');
		map[i] = ft_aatoai(splitted_line);
		free(splitted_line);
		free(line);
		i++;
	}
	map[i] = NULL;
	return (map);
}
