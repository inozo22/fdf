/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:55:19 by nimai             #+#    #+#             */
/*   Updated: 2023/03/22 12:13:54 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//May I bundle two functions below
void	convert_points_2d(t_fdf *fdf, t_data *data)
{
	double	x_aux;
	double	y_aux;
	int		i;
	int		j;

	j = -1;
	while (++j < fdf->column)
	{
		i = -1;
		while (++i < fdf->row_len)
		{
			x_aux = sqrt(1.0 / 2) * (fdf->n[j][i].x - fdf->n[j][i].y);
			y_aux = sqrt(1.0 / 6) * (fdf->n[j][i].x + fdf->n[j][i].y - 2 * fdf->n[j][i].z);
			fdf->n[j][i].x = x_aux * 200;
			fdf->n[j][i].y = y_aux * 200;
		}
	}
	return ;
}
