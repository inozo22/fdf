/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:45:20 by nimai             #+#    #+#             */
/*   Updated: 2023/04/18 15:52:23 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	terminate_fdf(void	*param)
{
	t_f	*meta;

	meta = (t_f *)param;
	mlx_destroy_window(meta->map->vars.mlx, meta->map->vars.win);
	all_free(meta);
//	free (meta->map->vars.mlx);
	system ("leaks fdf");
	exit (0);
}

void	zoom(int key, t_map *map)
{
	if (key == 125)
		map->mag++;
	if (key == 126)
		map->mag--;
}

void	control_keys(int key, t_f *f)
{
	if (key == KEY_ESC || key == KEY_Q)
		terminate_fdf(f);
	if (key == 126 || key == 125)
		zoom(key, f->map);
}

int	key_press(int key, void *param)
{
	t_f	*f;

	f = (t_f *)param;
	control_keys(key, f);
	return (0);
}
