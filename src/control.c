/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:45:20 by nimai             #+#    #+#             */
/*   Updated: 2023/05/02 16:30:59 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	terminate_fdf(void	*param)
{
	t_f	*meta;

	meta = (t_f *)param;
	mlx_destroy_window(meta->map->vars.mlx, meta->map->vars.win);
	all_free(meta);
	system ("leaks fdf");
	exit (0);
}

void	control_keys(int key, t_f *f)
{
	if (key == KEY_ESC || key == KEY_Q)
		terminate_fdf(f);
}

int	key_press(int key, void *param)
{
	t_f	*f;

	f = (t_f *)param;
	control_keys(key, f);
	return (0);
}
