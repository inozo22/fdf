/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:56:38 by nimai             #+#    #+#             */
/*   Updated: 2023/03/16 17:53:58 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		close_win(int keycode, t_map *map)//if I don't have this, I will get segumentation fault
{
	mlx_destroy_window(map->vars.mlx, map->vars.win);
//	mlx_destroy_image(map->vars.mlx, map->data.img);
	return (0);
}
//if I put this line instead of close_win, I will get segufault mlx_hook(mlx->win, 2, 1L<<0, mlx_destroy_window, mlx);//close the window with any key

void	open_window(t_fdf *fdf, t_map *map)
{
	long	width;
	long	height;

//check the map size
	if ((fdf->row_len * 50) > 1920)
		width = 1920;
	else
		width = fdf->row_len * 50;
	if ((fdf->column * 50) > 1080)
		height = 1080;
	else
		height = fdf->column * 50;
	map->vars.mlx = mlx_init();
	map->vars.win = mlx_new_window(map->vars.mlx, width, height, "fdf");
	map->data.img = mlx_new_image(map->vars.mlx, width, height);
	map->data.addr = mlx_get_data_addr(map->data.img, &map->data.bits_per_pixel, &map->data.line_length, &map->data.endian);
	draw_map(map, fdf);
	mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->data.img, 0, 0);


	mlx_hook(map->vars.win, 2, 1L<<0, close_win, map);
	mlx_loop(map->vars.mlx);
//	free (map->vars.win);
//	free (map->vars.mlx);
}
