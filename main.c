/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:50:40 by nimai             #+#    #+#             */
/*   Updated: 2023/03/11 12:50:36 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//#include <stdlib.h>
//#include <mlx.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x = 5;
	int		y = 5;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Kaixo!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

//squares
/* 	while (x++ < 505)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (y++ < 505)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (x-- > 5)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (y-- >= 5)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000); */
//circles

//triangles
/* 	x = 750;
	y = 250;
	while (y++ < 500)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (x-- > 500)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (y-- > 250 && x++ < 750)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000); */

//kore dekinai
/* 	x = 750;
	y = 250;
	while (y++ < 600)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (x-- > 500)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (y-- > 250 && x++ < 750)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000); */

//yappari dekinai?
/*  	x = 750;
	y = 250;
	while (x++ < 875)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (y-- > 0)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (y++ < 250 && x-- > 750)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000); */

//hexagons
	x = 1000;
	y = 250;
	while (x++ < 1250 && y-- > 125)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (x++ < 1500 && y++ < 250)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (y++ < 375)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (x-- > 1000 && y++ < 500)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (x-- > 750 && y-- > 375)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	while (y-- > 250)
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
