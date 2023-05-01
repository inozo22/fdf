/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:55:19 by nimai             #+#    #+#             */
/*   Updated: 2023/05/01 13:16:54 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	convert_points_2d(t_f *f)
{
	double	x_aux;
	double	y_aux;
	int		i;
	int		j;

	j = -1;
	while (++j < f->column)
	{
		i = -1;
		while (++i < f->row_len)
		{
			x_aux = sqrt(1.0 / 2) * (f->n[j][i].x - f->n[j][i].y);
			y_aux = sqrt(1.0 / 6) * (f->n[j][i].x + f->n[j][i].y \
			- 2 * f->n[j][i].z);
			f->n[j][i].x = x_aux * 200;
			f->n[j][i].y = y_aux * 200;
		}
	}
	return ;
}
