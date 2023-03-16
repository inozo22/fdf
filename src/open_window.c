/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:56:38 by nimai             #+#    #+#             */
/*   Updated: 2023/03/16 11:24:48 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//I think I should use 

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	printf("data: %p\n", data);	

	printf("data->addr: %p\ndata->line_length: %d\ndata->bits_per_pixel: %d\n", data->addr, data->line_length, data->bits_per_pixel);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	printf("data->addr: %p\ndata->line_length: %d\ndata->bits_per_pixel: %d\n", data->addr, (y * data->line_length), (x * data->bits_per_pixel));
	*(unsigned int *)dst = color;
}

/* t_mlx	*init_mlx(t_mlx *mlx)
{
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		exit (hollow_error(4));
	return (mlx);
	

} */

int		close_win(int keycode, t_map *map)//if I don't have this, I will get segumentation fault
{
	mlx_destroy_window(map->vars.mlx, map->vars.win);
	mlx_destroy_image(map->vars.mlx, map->data.img);
	return (0);
}

void	open_window(t_fdf *fdf, t_map *map)
{
//	void	*mlx_win;
	long	width;
	long	height;
//	t_data	img;

//check the map size
	if ((fdf->row_len * 50) > 1920)
		width = 1920;
	else
		width = fdf->row_len * 50;
	if ((fdf->column * 50) > 1080)
		height = 1080;
	else
		height = fdf->column * 50;
//	printf("fdf->column: %ld\nfdf->row_len: %ld\n", fdf->column, fdf->row_len);
	map->vars.mlx = mlx_init();
//	printf("1st mlx->mlx: %p\n", mlx->mlx);
	map->vars.win = mlx_new_window(map->vars.mlx, width, height, "fdf");
//	printf("1st mlx->win: %p\n", mlx->win);	
//	printf("2nd mlx->mlx: %p\n", mlx->mlx);
	map->data.img = mlx_new_image(map->vars.mlx, width, height);
//	printf("3rd mlx->mlx: %p\n", mlx->mlx);
	map->data.addr = mlx_get_data_addr(map->data.img, &map->data.bits_per_pixel, &map->data.line_length, &map->data.endian);
//	printf("mlx->data: %p\n", mlx->data);
	my_mlx_pixel_put(&map->data, 5, 5, 0xfcbc48);//I think I should use function minilibX
	mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->data.img, 0, 0);
/* 	if (condition)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
	} */
//	mlx_hook(mlx->win, 2, 1L<<0, mlx_destroy_window, mlx);//close the window with any key
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
