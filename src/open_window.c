/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:56:38 by nimai             #+#    #+#             */
/*   Updated: 2023/03/20 14:35:29 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	terminate_fdf(void	*param)
{
	t_map	*meta;

	meta = (t_map *)param;
	mlx_destroy_window(meta->vars.mlx, meta->vars.win);
//	free(meta->data.addr);
	exit (0);
}

void	control_keys(int key, t_map *map)
{
	if (key == KEY_ESC || key == KEY_Q)
	{
		terminate_fdf(map);
	}
}

int	key_press(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	control_keys(key, map);
	return (0);
}

/* int		close_win(int keycode, t_map *map)//if I don't have this, I will get segumentation fault
{
	mlx_destroy_window(map->vars.mlx, map->vars.win);
//	mlx_destroy_image(map->vars.mlx, map->data.img);
	return (0);
} */
//if I put this line instead of close_win, I will get segufault mlx_hook(mlx->win, 2, 1L<<0, mlx_destroy_window, mlx);//close the window with any key

void	open_window(t_fdf *fdf, t_map *map)
{
//	long	width;
//	long	height;

//Move to get_size in fdf.c
//check the map size
/* 	if ((fdf->row_len * 50) > 1920)
		width = 1920;
	else
		width = fdf->row_len * 50;
	if ((fdf->column * 50) > 1080)
		height = 1080;
	else
		height = fdf->column * 50; */

	map->vars.mlx = mlx_init();
	map->vars.win = mlx_new_window(map->vars.mlx, fdf->width, fdf->height, "fdf");
	map->data.img = mlx_new_image(map->vars.mlx, fdf->width, fdf->height);
	map->data.addr = mlx_get_data_addr(map->data.img, &map->data.bits_per_pixel, &map->data.line_length, &map->data.endian);
	draw_map(map, fdf);
	mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->data.img, 0, 0);


//	mlx_hook(map->vars.win, 2, 1L<<0, close_win, map);
	mlx_hook(map->vars.win, 2, 0, key_press, map);//20230317 It works exit with esc
	mlx_loop(map->vars.mlx);
//	free (map->vars.win);
//	free (map->vars.mlx);
}
