/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:53:50 by aaggery           #+#    #+#             */
/*   Updated: 2014/12/28 23:39:08 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keyboard_event(int keycode, t_fdf *fdf)
{
	(void)fdf;
	printf("key pressed: %d\n", keycode);
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
	draw_map(fdf);
	return (0);
}
