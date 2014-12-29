/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 10:13:33 by aaggery           #+#    #+#             */
/*   Updated: 2014/12/29 21:55:03 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		dump_map(int ***map)
{
	int		x;
	int		y;

	printf("--- Dumping map ---\n\n");
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			printf("%d ", map[y][x][0]);
			x++;
		}
		printf("NULL - %d\n", x);
		y++;
	}
	printf("NULL\n");
	printf("\n--- End of dump ---\n\n");
}

static void		ft_init(t_fdf *fdf, char *file)
{
	fdf->map.map = ft_load_map(file);
	fdf->map.alpha = 32;
	fdf->map.beta = 32;
	fdf->map.offset.x = WIN_WIDTH / 2;
	fdf->map.offset.y = WIN_HEIGHT / 4;
	fdf->map.scale = 32;
	fdf->map.depth = 0.1;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "42 fdf");
	fdf->buffer.width = WIN_WIDTH;
	fdf->buffer.height = WIN_HEIGHT;
	fdf->buffer.img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->buffer.data = mlx_get_data_addr(fdf->buffer.img, &(fdf->buffer.bpp),
			&(fdf->buffer.line_size), &(fdf->buffer.endian));
}

static void		ft_check_args(int argc, char **argv)
{
	int		fd;

	if (argc > 2)
	{
		ft_putendl_fd("Error, too much arguments.", 2);
		exit(EXIT_FAILURE);
	}
	else if (argc < 2)
	{
		ft_putendl_fd("Error, please specify a map.", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error, file not found.", 2);
		exit(EXIT_FAILURE);
	}
	else
		close(fd);
}

int				main(int argc, char **argv)
{
	t_fdf		fdf;

	ft_check_args(argc, argv);
	ft_init(&fdf, argv[1]);
	dump_map(fdf.map.map);
	mlx_expose_hook(fdf.win, draw_map, &fdf);
	mlx_key_hook(fdf.win, keyboard_event, &fdf);
	mlx_mouse_hook(fdf.win, mouse_event, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
