/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:53:50 by aaggery           #+#    #+#             */
/*   Updated: 2014/12/30 00:27:13 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_reset_map(t_fdf *fdf)
{
	fdf->map.scale = 32;
	fdf->map.depth = 0.1;
	fdf->map.alpha = 30;
	fdf->map.beta = 30;
	fdf->map.offset.x = WIN_WIDTH / 2;
	fdf->map.offset.y = WIN_HEIGHT / 8;
}

int				keyboard_event(int keycode, t_fdf *fdf)
{
	if (keycode == KEYCODE_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == KEYCODE_ZOOMIN)
		fdf->map.scale += ZOOMSTEP;
	else if (keycode == KEYCODE_ZOOMOUT && fdf->map.scale - ZOOMSTEP > 0)
		fdf->map.scale -= ZOOMSTEP;
	else if (keycode == KEYCODE_DEPTHADD)
		fdf->map.depth += DEPTHSTEP;
	else if (keycode == KEYCODE_DEPTHSUB)
		fdf->map.depth -= DEPTHSTEP;
	else if (keycode == KEYCODE_MOVEUP)
		fdf->map.offset.y += MOVESTEP;
	else if (keycode == KEYCODE_MOVERIGHT)
		fdf->map.offset.x -= MOVESTEP;
	else if (keycode == KEYCODE_MOVEDOWN)
		fdf->map.offset.y -= MOVESTEP;
	else if (keycode == KEYCODE_MOVELEFT)
		fdf->map.offset.x += MOVESTEP;
	else if (keycode == KEYCODE_RESET)
		ft_reset_map(fdf);
	draw_map(fdf);
	return (0);
}

int				mouse_event(int button, int x, int y, t_fdf *fdf)
{
	if (button == KEYCODE_ROTLEFT)
	{
		fdf->map.alpha += ROTSTEP;
		fdf->map.beta -= ROTSTEP;
	}
	else if (button == KEYCODE_ROTRIGHT)
	{
		fdf->map.alpha -= ROTSTEP;
		fdf->map.beta += ROTSTEP;
	}
	else if (button == KEYCODE_CLICK)
	{
		fdf->map.offset.x = x;
		fdf->map.offset.y = y;
	}
	draw_map(fdf);
	return (0);
}
