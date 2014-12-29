/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 10:05:39 by aaggery           #+#    #+#             */
/*   Updated: 2014/12/29 21:53:14 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include <stdio.h> // A virer!

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define RAD(x) (x * M_PI / 180)
# define DEG(x) (x * 180 / M_PI)

# define KEYCODE_ESC 53
# define KEYCODE_ZOOMIN 69
# define KEYCODE_ZOOMOUT 78
# define KEYCODE_DEPTHADD 116
# define KEYCODE_DEPTHSUB 121
# define KEYCODE_MOVEUP 126
# define KEYCODE_MOVERIGHT 124
# define KEYCODE_MOVEDOWN 125
# define KEYCODE_MOVELEFT 123
# define KEYCODE_ROTRIGHT 4
# define KEYCODE_ROTLEFT 5
# define KEYCODE_CLICK 1
# define KEYCODE_RESET 49

# define MOVESTEP 32
# define ZOOMSTEP 4
# define DEPTHSTEP 0.1
# define ROTSTEP 8

typedef struct	s_point2d
{
	int			x;
	int			y;
}				t_point2d;

typedef struct	s_map
{
	int			***map;
	int			alpha;
	int			beta;
	t_point2d	offset;
	int			scale;
	float		depth;
}				t_map;

typedef struct	s_buffer
{
	void		*img;
	char		*data;
	int			bpp;
	int			line_size;
	int			endian;
	int			width;
	int			height;
}				t_buffer;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_buffer	buffer;
}				t_fdf;

/*
 * Prototypes from "get_next_line.c"
*/

int				get_next_line(int fd, char **line);

/*
 * Prototypes from "map.c"
*/

int				***ft_load_map(char *file);

/*
 * Prototypes from "draw.c"
*/

int				draw_map(t_fdf *fdf);

/*
 * Prototypes from "events.c"
*/

int				keyboard_event(int keycode, t_fdf *fdf);
int				mouse_event(int button, int x, int y, t_fdf *fdf);

/*
 * Prototypes from "tools.c"
*/

void			ft_put_pixel_to_img(t_buffer *buffer, int x, int y, int color);
int				ft_is_in_window(int bounds_width, int bounds_height, int x, int y);
void			ft_draw_line(t_fdf *fdf, t_point2d start, t_point2d end, int color);

#endif
