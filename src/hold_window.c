/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hold_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:45:20 by nimai             #+#    #+#             */
/*   Updated: 2023/03/22 09:56:21 by nimai            ###   ########.fr       */
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
	int		i;
	int		j;
	double	x_max;
	double	x_min;

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
//	printf("where am I: %d\nfdf->data.center_x: %d\n", __LINE__, map->data.center_x);
}

void	get_mid_y(t_fdf *fdf, t_map *map)
{
	int		i;
	int		j;
	double	y_max;
	double	y_min;

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
//	printf("where am I: %d\nfdf->data.center_y: %d\n", __LINE__, map->data.center_y);
}

void	get_scale(t_map *map)
{
	double	vertical;
	double	horizontal;

	vertical = (WIN_HEIGHT - 0.0) / map->data.height;
	horizontal = (WIN_WIDTH - 0.0) / map->data.width;
	if (vertical > horizontal)
		map->data.scale = horizontal;
	else
		map->data.scale = vertical;
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
			fdf->n[j][i].x_mod = map->data.scale * 0.8 * (fdf->n[j][i].x - map->data.center_x) + WIN_WIDTH / 2;
			fdf->n[j][i].y_mod = map->data.scale * 0.8 * (fdf->n[j][i].y - map->data.center_y) + WIN_HEIGHT / 2;
//			printf("x_mod: %d\ny_mod: %d\n", fdf->n[j][i].x_mod, fdf->n[j][i].y_mod);
			i++;
		}
		j++;
	}
	printf("where am I: %d\nmap->data.scale: %f\n", __LINE__, map->data.scale);
}

void	draw_ver(t_map *map, t_fdf *fdf)//check all rows
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = -1;
	while (++j < fdf->column)
	{
		i = -1;
		while (++i < fdf->row_len)
		{
			x = fdf->n[j][i].x_mod;
			y = fdf->n[j][i].y_mod;
//			printf("x: %d\ny: %d\n", x, y);
			if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
				my_mlx_pixel_put(&map->data, x, y, 0xfcbc48);
		}
	}
	return ;
}

void	hold_window(t_fdf *fdf, t_map *map)
{
//	printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
//	convert_points_2d(fdf, &map->data);
//	printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
//	get_mid_x(fdf, map);
//	get_mid_y(fdf, map);
//	get_scale(map);
	adjust_screen(fdf, map);
//	printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
	three_dimension(fdf, map);
//	printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
//	draw_ver(map, fdf);
//	printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
	mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->data.img, 0, 0);
	mlx_hook(map->vars.win, 2, 0, key_press, map);
	mlx_loop(map->vars.mlx);
}
