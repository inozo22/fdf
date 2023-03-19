/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:55:19 by nimai             #+#    #+#             */
/*   Updated: 2023/03/17 14:24:26 by nimai            ###   ########.fr       */
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

void	put_line_right(t_map *map, t_fdf *fdf, long y, long x)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < fdf->w_cell)//20230319
		my_mlx_pixel_put(&map->data, ((x * fdf->w_cell) + (fdf->width * 0.125) + i), ((y * fdf->w_cell) + (fdf->height * 0.125) + j), 0xfcbc48);//20230319
}
//(fdf->width * 0.125), at this moment, set the first point of the map like that, because the map is 75% of image size and windows size, to array to the center, more or less 12.5 % of margin is fine, I think
//test with MAC

void	put_line_down(t_map *map, t_fdf *fdf, long y, long x)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++j < fdf->w_cell)//20230319, I have to adjust to the height, but after calculating 
		my_mlx_pixel_put(&map->data, ((x * fdf->w_cell) + (fdf->width * 0.125) + i), ((y * fdf->w_cell) + (fdf->height * 0.125) + j), 0xfcbc48);//20230319
}
//May I bundle two functions above

void	draw_map(t_map *map, t_fdf *fdf)//check all rows
{
	long	i;
	long	j;

	i = -1;
	j = -1;
	printf("column: %ld", fdf->column);
	while (++j < fdf->column)
	{
		while (++i < fdf->row_len)
		{
			if (fdf->n[j][i].value < INTMIN || fdf->n[j][i].value > INTMAX)//check the first row->OK
				exit (fdf_error(4, fdf));
			if (i != fdf->row_len - 1)
			{
				if (fdf->n[j][i].value == fdf->n[j][i + 1].value)//order to draw the line
					put_line_right(map, fdf, j, i);
/* 				else
					printf("calculate the slope\n"); */
			}
			if (j != fdf->column - 1)
			{
				if (fdf->n[j][i].value == fdf->n[j + 1][i].value)//order to draw the line
					put_line_down(map, fdf, j, i);
/* 				else
					printf("calculate the slope\n"); */
			}
		}
		i = -1;
	}
}

