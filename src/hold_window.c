/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hold_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:45:20 by nimai             #+#    #+#             */
/*   Updated: 2023/03/20 15:07:17 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	terminate_fdf(void	*param)
{
	t_map	*meta;

	meta = (t_map *)param;
	mlx_destroy_window(meta->vars.mlx, meta->vars.win);
//	free(meta->data.addr);
	exit (0);
}

//If I want to put more function with key, here
void	control_keys(int key, t_map *map)
{
	if (key == KEY_ESC || key == KEY_Q)
		terminate_fdf(map);
}

int	key_press(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	control_keys(key, map);
	return (0);
}

void	adjust_screen(t_fdf *fdf, t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < fdf->column)
	{
		i = 0;
		while (i < fdf->row_len)
		{
			fdf->n[j][i].len_x = fdf->width * 0.9 * (points[j][i].x	- data->map_center_x) + WIN_WIDTH / 2;
			fdf->n[j][i].len_y = fdf->height * 0.9 * (points[j][i].y - data->map_center_y) + WIN_HEIGHT / 2;
			i++;
		}
		j++;
	}
}

void	hold_window(t_fdf *fdf, t_map *map)
{
	adjust_screen(fdf, map);
	draw_map(map, fdf);
	mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->data.img, 0, 0);


//	mlx_hook(map->vars.win, 2, 1L<<0, close_win, map);
	mlx_hook(map->vars.win, 2, 0, key_press, map);//20230317 It works exit with esc
	mlx_loop(map->vars.mlx);
//	free (map->vars.win);
//	free (map->vars.mlx);

}

