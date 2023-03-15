/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:56:38 by nimai             #+#    #+#             */
/*   Updated: 2023/03/15 11:06:39 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	open_window(t_fdf *fdf)
{
	void	*mlx;
	void	*mlx_win;
	long	width;
	long	height;
	t_data	img;

	if ((fdf->row_len * 50) > 1920)
		width = 1920;
	else
		width = fdf->row_len * 50;
	if ((fdf->column * 50) > 1080)
		height = 1080;
	else
		height = fdf->column * 50;
	printf("fdf->column: %ld\nfdf->row_len: %ld\n", fdf->column, fdf->row_len);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "fdf");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0xfcbc48);//I think I should use function minilibX
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

/* void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
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
	long	color;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Kaixo!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);


	x = 1000;
	y = 250;
	color = 0x00FF0000;

	while (x++ < 1250 && y-- > 125 && color)
		my_mlx_pixel_put(&img, x, y, color);
	while (x++ < 1500 && y++ < 250)
		my_mlx_pixel_put(&img, x, y, color);
	while (y++ < 375)
		my_mlx_pixel_put(&img, x, y, color);
	while (x-- > 1000 && y++ < 500)
		my_mlx_pixel_put(&img, x, y, color);
	while (x-- > 750 && y-- > 375)
		my_mlx_pixel_put(&img, x, y, color);
	while (y-- > 250)
		my_mlx_pixel_put(&img, x, y, color);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
} */
