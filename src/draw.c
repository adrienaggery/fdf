/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:31:24 by aaggery           #+#    #+#             */
/*   Updated: 2014/12/29 00:00:21 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

static t_point2d		ft_get_iso_point(t_fdf *fdf, int x, int y, int z)
{
	t_point2d		pt;

	pt.x = fdf->map.scale * (x * cos(RAD(ALPHA)) - y * cos(RAD(BETA)));
	pt.y = -(fdf->map.scale) * ((z * fdf->map.depth) - x * 
			sin(RAD(ALPHA)) - y * sin(RAD(BETA)));
	pt.x += fdf->map.offset.x;
	pt.y += fdf->map.offset.y;
	return (pt);
}

static int				ft_have_upper_point(int ***map, int x, int y)
{
	int		i;

	if (y > 0)
	{
		i = 0;
		while (map[y - 1][i])
			i++;
		if (i > x)
			return (1);
	}
	return (0);
}

static void				ft_buff_image(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (fdf->map.map[y])
	{
		x = 0;
		while (fdf->map.map[y][x])
		{
			if (fdf->map.map[y][x + 1])
				ft_draw_line(fdf, ft_get_iso_point(fdf, x, y, fdf->map.map[y][x][0]),
						ft_get_iso_point(fdf, x + 1, y, fdf->map.map[y][x + 1][0]), 0xFFFFFF);
			if (ft_have_upper_point(fdf->map.map, x, y))
				ft_draw_line(fdf, ft_get_iso_point(fdf, x, y, fdf->map.map[y][x][0]),
						ft_get_iso_point(fdf, x, y - 1, fdf->map.map[y - 1][x][0]), 0xFFFFFF);
			x++;
		}
		y++;
	}
}

int						draw_map(t_fdf *fdf)
{
	ft_bzero(fdf->buffer.data, fdf->buffer.line_size * fdf->buffer.height);
	ft_buff_image(fdf);
	printf("Image buffed\n");
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->buffer.img, 0, 0);
	return (0);
}
