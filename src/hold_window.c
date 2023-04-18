/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hold_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:45:20 by nimai             #+#    #+#             */
/*   Updated: 2023/04/18 15:38:43 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	get_mid_x(t_f *f)
{
	int		i;
	int		j;
	double	x_max;
	double	x_min;

	x_max = f->n[0][0].x;
	x_min = f->n[0][0].x;
	j = -1;
	while (++j < f->column)
	{
		i = -1;
		while (++i < f->row_len)
		{
			if (f->n[j][i].x > x_max)
				x_max = f->n[j][i].x;
			if (f->n[j][i].x < x_min)
				x_min = f->n[j][i].x;
		}
	}
	f->map->data.center_x = (x_max + x_min) / 2;
	f->map->data.width = x_max - x_min;
}

void	get_mid_y(t_f *f)
{
	int		i;
	int		j;
	double	y_max;
	double	y_min;

	y_max = f->n[0][0].y;
	y_min = f->n[0][0].y;
	j = -1;
	while (++j < f->column)
	{
		i = -1;
		while (++i < f->row_len)
		{
			if (f->n[j][i].y > y_max)
				y_max = f->n[j][i].y;
			if (f->n[j][i].y < y_min)
				y_min = f->n[j][i].y;
		}
	}
	f->map->data.center_y = (y_max + y_min) / 2;
	f->map->data.height = y_max - y_min;
}

void	get_scale(t_f *f)
{
	double	vertical;
	double	horizontal;

	vertical = (WIN_HEIGHT - 0.0) / f->map->data.height;
	horizontal = (WIN_WIDTH - 0.0) / f->map->data.width;
	if (vertical > horizontal)
		f->map->data.scale = horizontal;
	else
		f->map->data.scale = vertical;
}

void	adjust_screen(t_f *f)
{
	int	i;
	int	j;

	j = 0;
	while (j < f->column)
	{
		i = 0;
		while (i < f->row_len)
		{
			f->n[j][i].x_mod = f->map->data.scale * f->map->mag * \
			(f->n[j][i].x - f->map->data.center_x) + WIN_WIDTH / 2;
			f->n[j][i].y_mod = f->map->data.scale * f->map->mag * \
			(f->n[j][i].y - f->map->data.center_y) + WIN_HEIGHT / 2;
			i++;
		}
		j++;
	}
}

void	hold_window(t_f *f)
{
	adjust_screen(f);
	three_dimension(f);
	mlx_put_image_to_window(f->map->vars.mlx, f->map->vars.win, \
	f->map->data.img, 0, 0);
	mlx_hook(f->map->vars.win, 2, 0, key_press, f);
	mlx_hook(f->map->vars.win, 17, 0, terminate_fdf, f);
	mlx_loop(f->map->vars.mlx);
}
