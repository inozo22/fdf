/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:56:38 by nimai             #+#    #+#             */
/*   Updated: 2023/03/16 11:56:22 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//I think I should use 

/* void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_lines(t_map *map, t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < 15)
	{
		my_mlx_pixel_put(&map->data, 5 + i, 5 + j, 0xfcbc48);
	}
	i = 0;
	j = -1;
	while (++j < 15)
	{
		my_mlx_pixel_put(&map->data, 5 + i, 5 + j, 0xfcbc48);
	}
} */

int		close_win(int keycode, t_map *map)//if I don't have this, I will get segumentation fault
{
	mlx_destroy_window(map->vars.mlx, map->vars.win);
	mlx_destroy_image(map->vars.mlx, map->data.img);
	return (0);
}
//if I put this line instead of close_win, I will get segufault mlx_hook(mlx->win, 2, 1L<<0, mlx_destroy_window, mlx);//close the window with any key

void	open_window(t_fdf *fdf, t_map *map)
{
	long	width;
	long	height;

//check the map size
	if ((fdf->row_len * 50) > 1920)
		width = 1920;
	else
		width = fdf->row_len * 50;
	if ((fdf->column * 50) > 1080)
		height = 1080;
	else
		height = fdf->column * 50;
	map->vars.mlx = mlx_init();
	map->vars.win = mlx_new_window(map->vars.mlx, width, height, "fdf");
	map->data.img = mlx_new_image(map->vars.mlx, width, height);
	map->data.addr = mlx_get_data_addr(map->data.img, &map->data.bits_per_pixel, &map->data.line_length, &map->data.endian);
//	my_mlx_pixel_put(&map->data, 5, 5, 0xfcbc48);//I think I should use function minilibX
//	draw_lines(map, fdf);
	draw_map(map, fdf);
	mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->data.img, 0, 0);


	mlx_hook(map->vars.win, 2, 1L<<0, close_win, map);
	mlx_loop(map->vars.mlx);
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
