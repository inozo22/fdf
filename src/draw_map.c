/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:55:19 by nimai             #+#    #+#             */
/*   Updated: 2023/03/21 17:39:54 by nimai            ###   ########.fr       */
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
			printf("where am I: %d\nfile: %s\nfdf->[j][i].x: %d, fdf->[j][i].y: %d\n", __LINE__, __FILE__, fdf->n[j][i].x, fdf->n[j][i].y);//no llego
		}
	}
//	printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);//no llego
	return ;
}

/* void	put_line_right(t_map *map, t_fdf *fdf, int y, int x)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < fdf->w_cell)//20230319
	{
	//	convert_points_2d(fdf, data);
		my_mlx_pixel_put(&map->data, ((x * fdf->w_cell) + (fdf->width * 0.125) + i), ((y * fdf->w_cell) + (fdf->height * 0.125) + j), 0xfcbc48);//20230319
	}

}
//(fdf->width * 0.125), at this moment, set the first point of the map like that, because the map is 75% of image size and windows size, to array to the center, more or less 12.5 % of margin is fine, I think
//test with MAC

void	put_line_down(t_map *map, t_fdf *fdf, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++j < fdf->w_cell)//20230319, I have to adjust to the height, but after calculating 
		my_mlx_pixel_put(&map->data, ((x * fdf->w_cell) + (fdf->width * 0.125) + i), ((y * fdf->w_cell) + (fdf->height * 0.125) + j), 0xfcbc48);//20230319
} */
//May I bundle two functions above
