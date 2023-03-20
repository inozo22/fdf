/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hold_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:45:20 by nimai             #+#    #+#             */
/*   Updated: 2023/03/20 17:49:10 by nimai            ###   ########.fr       */
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

//If I want to put more function with key, here
void	control_keys(int key, t_map *map)
{
	if (key == KEY_ESC || key == KEY_Q)
		terminate_fdf(map);
}

int	key_press(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	control_keys(key, map);
	return (0);
}

void	get_mid_x(t_fdf *fdf, t_map *map)
{
	long	i;
	long	j;
	long	x_max;
	long	x_min;

	x_max = fdf->n[0][0].x;
	x_min = fdf->n[0][0].x;
	j = -1;
	while (++j < fdf->column)
	{
		i = -1;
		while (++i < fdf->row_len)
		{
			if (fdf->n[j][i].x > x_max)
				x_max = fdf->n[j][i].x;
			if (fdf->n[j][i].x < x_min)
				x_min = fdf->n[j][i].x;
		}
	}
	map->data.center_x = (x_max + x_min) / 2;
	map->data.width = x_max - x_min;
}

void	get_mid_y(t_fdf *fdf, t_map *map)
{
	long	i;
	long	j;
	long	y_max;
	long	y_min;

	y_max = fdf->n[0][0].y;
	y_min = fdf->n[0][0].y;
	j = -1;
	while (++j < fdf->column)
	{
		i = -1;
		while (++i < fdf->row_len)
		{
			if (fdf->n[j][i].y > y_max)
				y_max = fdf->n[j][i].y;
			if (fdf->n[j][i].y < y_min)
				y_min = fdf->n[j][i].y;
		}
	}
	map->data.center_y = (y_max + y_min) / 2;
	map->data.height = y_max - y_min;
}

void	get_scale(t_map *map)
{
	long	ver;
	long	hori;

	ver = (WIN_HEIGHT - 0) / map->data.height;
	hori = (WIN_WIDTH - 0) / map->data.width;
	if (ver > hori)
		map->data.scale = hori;
	else
		map->data.scale = ver;
}

void	adjust_screen(t_fdf *fdf, t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < fdf->column)
	{
		i = 0;
		while (i < fdf->row_len)
		{
			fdf->n[j][i].x_mod = map->data.scale * 0.9 * (fdf->n[j][i].x - map->data.center_x) + WIN_WIDTH / 2;
			fdf->n[j][i].y_mod = map->data.scale * 0.9 * (fdf->n[j][i].y - map->data.center_y) + WIN_HEIGHT / 2;
			i++;
		}
		j++;
	}
}

void	draw_map(t_map *map, t_fdf *fdf)//check all rows
{
	long	i;
	long	j;
	long	x;
	long	y;

	j = -1;
	while (++j < fdf->column)
	{
		i = -1;
		while (++i < fdf->row_len)
		{
			x = fdf->n[j][i].x_mod;
			y = fdf->n[j][i].y_mod;
			if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
				my_mlx_pixel_put(&map->data, x, y, 0xfcbc48);
		}
	}
}

void	hold_window(t_fdf *fdf, t_map *map)
{
//	convert_points_2d(fdf, &map->data);
/* 	get_mid_x(fdf, map);
	get_mid_y(fdf, map); */
	adjust_screen(fdf, map);
	three_dimension(fdf, map);
	draw_map(map, fdf);
	mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->data.img, 0, 0);
	mlx_hook(map->vars.win, 2, 0, key_press, map);
	mlx_loop(map->vars.mlx);
}
