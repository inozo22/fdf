/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:09:34 by nimai             #+#    #+#             */
/*   Updated: 2023/04/06 16:25:54 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	positive_low(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2)
{
	int	d[3];
	int	coord[2];
	int	len;

	len = 0;
	d[0] = nbr2.x_mod - nbr1.x_mod;
	d[1] = nbr2.y_mod - nbr1.y_mod;
	coord[0] = nbr1.x_mod;
	coord[1] = nbr1.y_mod;
	d[2] = 2 * d[1] - d[0];
	while (coord[0] < nbr2.x_mod)
	{
		if (d[2] >= 0)
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1.colour);//kore ha heikou
			coord[1]++;
			d[2] = d[2] + 2 * d[1] - 2 * d[0];
		}
		else
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1.colour);//kore ha heikou
			d[2] = d[2] + 2 * d[1];
		}
		coord[0]++;
		len++;
	}
	fdf->n[fdf->pwd_j][fdf->pwd_i].len = len;
}

void	positive_high(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2)
{
	int	d[3];
	int	coord[2];
	int	len;

	len = 0;
	d[0] = nbr2.x_mod - nbr1.x_mod;
	d[1] = nbr2.y_mod - nbr1.y_mod;
	coord[0] = nbr1.x_mod;
	coord[1] = nbr1.y_mod;
	d[2] = 2 * d[0] - d[1];
	while (coord[1] < nbr2.y_mod)
	{
		if (d[2] >= 0)
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1.colour);//migi naname shita
			coord[0]++;
			d[2] = d[2] + 2 * d[0] - 2 * d[1];
		}
		else
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1.colour);//migi naname shita
			d[2] = d[2] + 2 * d[0];
		}
		coord[1]++;
		len++;
	}
	fdf->n[fdf->pwd_j][fdf->pwd_i].len = len;
}

void	negative_low(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2)
{
	int	d[3];
	int	coord[2];
	int	len;

	len = 0;
	d[0] = nbr2.x_mod - nbr1.x_mod;
	d[1] = nbr2.y_mod - nbr1.y_mod;
	coord[0] = nbr1.x_mod;
	coord[1] = nbr1.y_mod;
	d[2] = 2 * d[1] - d[0];
	while (coord[0] < nbr2.x_mod)
	{
		if (d[2] >= 0)
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1.colour);//heikou
			coord[1]--;
			d[2] = d[2] - 2 * d[1] - 2 * d[0];
		}
		else
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1.colour);//heikou
			d[2] = d[2] - 2 * d[1];
		}
		coord[0]++;
		len++;

	}
	fdf->n[fdf->pwd_j][fdf->pwd_i].len = len;
}

void	negative_high(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2)
{
	int	d[3];
	int	coord[2];
	int	len;

	len = 0;
	d[0] = nbr2.x_mod - nbr1.x_mod;
	d[1] = nbr2.y_mod - nbr1.y_mod;
	coord[0] = nbr2.x_mod;
	coord[1] = nbr2.y_mod;
	d[2] = 2 * d[1] - d[0];
	while (coord[1] < nbr1.y_mod)
	{
		if (d[2] >= 0)
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1.colour);//hidari naname shita
			coord[0]--;
			d[2] = d[2] + 2 * d[0] + 2 * d[1];
		}
		else
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1.colour);//hidari naname shita
			d[2] = d[2] + 2 * d[0];
		}
		coord[1]++;
		len++;
	}
	fdf->n[fdf->pwd_j][fdf->pwd_i].len = len;
}
