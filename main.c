/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:50:40 by nimai             #+#    #+#             */
/*   Updated: 2023/03/11 09:42:46 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//#include <stdlib.h>
//#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Kaixo!");
//	img = mlx_new_image(mlx, 1920, 1080);
 	mlx_loop(mlx);
/*	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);  */
}

/* typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
} */

/* int	main(int ac, char **av)
{
	char	*str;
	int		fd;

	str = " ";
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}
 */