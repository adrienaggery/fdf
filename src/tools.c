/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 13:51:17 by aaggery           #+#    #+#             */
/*   Updated: 2014/12/28 23:41:31 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel_to_img(t_buffer *buffer, int x, int y, int color)
{
	int			octet;
	int			position;

	octet = buffer->line_size / buffer->width;
	if (y > 0)
		y -= 1;
	position = (buffer->line_size * y) + (x * octet);
	if (ft_memcmp(buffer->data + position, &color, octet) != 0)
		ft_memcpy(buffer->data + position, &color, octet);
}

int		ft_is_in(int bounds_width, int bounds_height, int x, int y)
{
	if (x >= 0 && x < bounds_width && y >= 0 && y < bounds_height)
		return (1);
	return (0);
}

void	ft_draw_line(t_fdf *fdf, t_point2d start, t_point2d end, int color)
{
	t_point2d		delta;
	t_point2d		inc;
	int				e;
	int				ee;

	if (!ft_is_in(fdf->buffer.width, fdf->buffer.height, start.x, start.y) &&
			!ft_is_in(fdf->buffer.width, fdf->buffer.height, end.x, end.y))
		return ;
	delta.x = abs(end.x - start.x);
	delta.y = abs(end.y - start.y);
	inc.x = (start.x < end.x) ? 1 : -1;
	inc.y = (start.y < end.y) ? 1 : -1;
	e = (delta.x > delta.y ? delta.x : -delta.y) / 2;
	while (1)
	{
		if (ft_is_in(fdf->buffer.width, fdf->buffer.height, start.x, start.y))
			ft_put_pixel_to_img(&fdf->buffer, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		ee = e;
		if (ee > -delta.x)
		{
			e -= delta.y;
			start.x += inc.x;
		}
		if (ee < delta.y)
		{
			e += delta.x;
			start.y += inc.y;
		}
	}
}
