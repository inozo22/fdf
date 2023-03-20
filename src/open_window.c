/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:56:38 by nimai             #+#    #+#             */
/*   Updated: 2023/03/20 15:07:19 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/* void	open_window(t_fdf *fdf, t_map *map)
{
	map->vars.mlx = mlx_init();
	map->vars.win = mlx_new_window(map->vars.mlx, fdf->width, fdf->height, "fdf");
	if (map->vars.mlx == NULL)
	{
		perror("Unable to create window pointer\n");
		exit(2);//memory release?
	}
	map->data.img = mlx_new_image(map->vars.mlx, fdf->width, fdf->height);
	map->data.addr = mlx_get_data_addr(map->data.img, &map->data.bits_per_pixel, &map->data.line_length, &map->data.endian);

} */
