/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:45:20 by nimai             #+#    #+#             */
/*   Updated: 2023/04/17 15:20:44 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	terminate_fdf(void	*param)
{
	t_map	*meta;

	meta = (t_map *)param;
	mlx_destroy_window(meta->vars.mlx, meta->vars.win);
	free(meta->vars.mlx);
	exit (0);
}

void	zoom(int key, t_map *map)
{
	if (key == 125)
		map->mag++;
	if (key == 126)
		map->mag--;
}

void	control_keys(int key, t_map *map)
{
	if (key == KEY_ESC || key == KEY_Q)
		terminate_fdf(map);
	if (key == 126 || key == 125)
		zoom(key, map);
}

int	key_press(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	control_keys(key, map);
	return (0);
}
