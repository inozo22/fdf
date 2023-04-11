/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:09:34 by nimai             #+#    #+#             */
/*   Updated: 2023/04/11 11:11:02 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	positive_low(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2)
{
	int	coord[2];

	fdf->n[fdf->pwd_j][fdf->pwd_i].len = 0;
	fdf->dx = nbr2.x_mod - nbr1.x_mod;
	fdf->dy = nbr2.y_mod - nbr1.y_mod;
	fdf->dd = 2 * fdf->dy - fdf->dx;
	coord[0] = nbr1.x_mod;
	coord[1] = nbr1.y_mod;
	while (coord[0] < nbr2.x_mod)
	{
		if (fdf->dd >= 0)
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1.colour);
			coord[1]++;
			fdf->dd = fdf->dd + 2 * fdf->dy - 2 * fdf->dx;
		}
		else
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1.colour);
			fdf->dd = fdf->dd + 2 * fdf->dy;
		}
		coord[0]++;
		fdf->n[fdf->pwd_j][fdf->pwd_i].len++;
	}
}

void	positive_high(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2)
{
	int	coord[2];

	fdf->n[fdf->pwd_j][fdf->pwd_i].len = 0;
	fdf->dx = nbr2.x_mod - nbr1.x_mod;
	fdf->dy = nbr2.y_mod - nbr1.y_mod;
	fdf->dd = 2 * fdf->dx - fdf->dy;
	coord[0] = nbr1.x_mod;
	coord[1] = nbr1.y_mod;
	while (coord[1] < nbr2.y_mod)
	{
		if (fdf->dd >= 0)
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1.colour);
			coord[0]++;
			fdf->dd = fdf->dd + 2 * fdf->dx - 2 * fdf->dy;
		}
		else
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1.colour);
			fdf->dd = fdf->dd + 2 * fdf->dx;
		}
		coord[1]++;
		fdf->n[fdf->pwd_j][fdf->pwd_i].len++;
	}
}

void	negative_low(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2)
{
	int	coord[2];

	fdf->n[fdf->pwd_j][fdf->pwd_i].len = 0;
	fdf->dx = nbr2.x_mod - nbr1.x_mod;
	fdf->dy = nbr2.y_mod - nbr1.y_mod;
	fdf->dd = 2 * fdf->dy - fdf->dx;
	coord[0] = nbr1.x_mod;
	coord[1] = nbr1.y_mod;
	while (coord[0] < nbr2.x_mod)
	{
		if (fdf->dd >= 0)
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1.colour);
			coord[1]--;
			fdf->dd = fdf->dd - 2 * fdf->dy - 2 * fdf->dx;
		}
		else
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1.colour);
			fdf->dd = fdf->dd - 2 * fdf->dy;
		}
		coord[0]++;
		fdf->n[fdf->pwd_j][fdf->pwd_i].len++;
	}
}

void	negative_high(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2)
{
	int	coord[2];

	fdf->n[fdf->pwd_j][fdf->pwd_i].len = 0;
	fdf->dx = nbr2.x_mod - nbr1.x_mod;
	fdf->dy = nbr2.y_mod - nbr1.y_mod;
	fdf->dd = 2 * fdf->dy - fdf->dx;
	coord[0] = nbr2.x_mod;
	coord[1] = nbr2.y_mod;
	while (coord[1] < nbr1.y_mod)
	{
		if (fdf->dd >= 0)
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1.colour);
			coord[0]--;
			fdf->dd = fdf->dd + 2 * fdf->dx + 2 * fdf->dy;
		}
		else
		{
			my_mlx_pixel_put(&map->data, coord[0], coord[1], nbr1.colour);
			fdf->dd = fdf->dd + 2 * fdf->dx;
		}
		coord[1]++;
		fdf->n[fdf->pwd_j][fdf->pwd_i].len++;
	}
}
