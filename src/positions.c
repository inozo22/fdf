/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:09:34 by nimai             #+#    #+#             */
/*   Updated: 2023/03/24 12:56:20 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	positive_low(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2)
{
	int	d[3];
	int	coord[2];

	d[0] = nbr2.x_mod - nbr1.x_mod;
	d[1] = nbr2.y_mod - nbr1.y_mod;
	coord[0] = nbr1.x_mod;
	coord[1] = nbr1.y_mod;
	d[2] = 2 * d[1] - d[0];
	while (coord[0] < nbr2.x_mod)
	{
		if (d[2] >= 0)
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1->colour);
			coord[1]++;
			d[2] = d[2] + 2 * d[1] - 2 * d[0];
		}
		else
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1->colour);
			d[2] = d[2] + 2 * d[1];
		}
		coord[0]++;
	}
}

void	positive_high(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2)
{
	int	d[3];
	int	coord[2];

	d[0] = nbr2.x_mod - nbr1.x_mod;
	d[1] = nbr2.y_mod - nbr1.y_mod;
	coord[0] = nbr1.x_mod;
	coord[1] = nbr1.y_mod;
	d[2] = 2 * d[0] - d[1];
	while (coord[1] < nbr2.y_mod)
	{
		if (d[2] >= 0)
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1->colour);
			coord[0]++;
			d[2] = d[2] + 2 * d[0] - 2 * d[1];
		}
		else
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1->colour);
			d[2] = d[2] + 2 * d[0];
		}
		coord[1]++;
	}
}

void	negative_low(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2)
{
	int	d[3];
	int	coord[2];

	d[0] = nbr2.x_mod - nbr1.x_mod;
	d[1] = nbr2.y_mod - nbr1.y_mod;
	coord[0] = nbr1.x_mod;
	coord[1] = nbr1.y_mod;
	d[2] = 2 * d[1] - d[0];
	while (coord[0] < nbr2.x_mod)
	{
		if (d[2] >= 0)
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1->colour);
			coord[1]--;
			d[2] = d[2] - 2 * d[1] - 2 * d[0];
		}
		else
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1->colour);
			d[2] = d[2] - 2 * d[1];
		}
		coord[0]++;
	}
}

void	negative_high(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2)
{
	int	d[3];
	int	coord[2];

	d[0] = nbr2.x_mod - nbr1.x_mod;
	d[1] = nbr2.y_mod - nbr1.y_mod;
	coord[0] = nbr2.x_mod;
	coord[1] = nbr2.y_mod;
	d[2] = 2 * d[1] - d[0];
	while (coord[1] < nbr1.y_mod)
	{
		if (d[2] >= 0)
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1->colour);
			coord[0]--;
			d[2] = d[2] + 2 * d[0] + 2 * d[1];
	//		printf("%x\n", );
		}
		else
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1->colour);
			d[2] = d[2] + 2 * d[0];
		}
		coord[1]++;
	}
}
