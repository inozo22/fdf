/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hold_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:45:20 by nimai             #+#    #+#             */
/*   Updated: 2023/04/17 13:05:34 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
			fdf->n[j][i].x_mod = map->data.scale * map->mag * \
			(fdf->n[j][i].x - map->data.center_x) + WIN_WIDTH / 2;
			fdf->n[j][i].y_mod = map->data.scale * map->mag * \
			(fdf->n[j][i].y - map->data.center_y) + WIN_HEIGHT / 2;
			i++;
		}
		j++;
	}
}

void	hold_window(t_fdf *fdf, t_map *map)
{
	adjust_screen(fdf, map);
	three_dimension(fdf, map);
	mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->data.img, 0, 0);
	mlx_hook(map->vars.win, 2, 0, key_press, map);
	mlx_hook(map->vars.win, 17, 0, terminate_fdf, map);
	mlx_loop(map->vars.mlx);
}
