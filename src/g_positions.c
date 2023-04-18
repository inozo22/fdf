/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_positions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:09:34 by nimai             #+#    #+#             */
/*   Updated: 2023/04/18 12:44:20 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	g_positive_low(t_f *f, t_nmbs nbr1, t_nmbs nbr2)
{
	int	coord[2];
	int	c;

	c = -1;
	f->dx = nbr2.x_mod - nbr1.x_mod;
	f->dy = nbr2.y_mod - nbr1.y_mod;
	f->dd = 2 * f->dy - f->dx;
	coord[0] = nbr1.x_mod;
	coord[1] = nbr1.y_mod;
	while ((coord[0] < nbr2.x_mod) && nbr1.grd[++c])
	{
		if (f->dd >= 0)
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[c]);
			coord[1]++;
			f->dd = f->dd + 2 * f->dy - 2 * f->dx;
		}
		else
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[c]);
			f->dd = f->dd + 2 * f->dy;
		}
		coord[0]++;
	}
}

void	g_positive_high(t_f *f, t_nmbs nbr1, t_nmbs nbr2)
{
	int	coord[2];
	int	c;

	c = -1;
	f->dx = nbr2.x_mod - nbr1.x_mod;
	f->dy = nbr2.y_mod - nbr1.y_mod;
	f->dd = 2 * f->dx - f->dy;
	coord[0] = nbr1.x_mod;
	coord[1] = nbr1.y_mod;
	while ((coord[1] < nbr2.y_mod) && nbr1.grd[++c])
	{
		if (f->dd >= 0)
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[c]);
			coord[0]++;
			f->dd = f->dd + 2 * f->dx - 2 * f->dy;
		}
		else
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[c]);
			f->dd = f->dd + 2 * f->dx;
		}
		coord[1]++;
	}
}

void	g_negative_low(t_f *f, t_nmbs nbr1, t_nmbs nbr2)
{
	int	coord[2];
	int	c;

	c = -1;
	f->dx = nbr2.x_mod - nbr1.x_mod;
	f->dy = nbr2.y_mod - nbr1.y_mod;
	f->dd = 2 * f->dy - f->dx;
	coord[0] = nbr1.x_mod;
	coord[1] = nbr1.y_mod;
	while ((coord[0] < nbr2.x_mod) && nbr1.grd[++c])
	{
		if (f->dd >= 0)
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[c]);
			coord[1]--;
			f->dd = f->dd - 2 * f->dy - 2 * f->dx;
		}
		else
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[c]);
			f->dd = f->dd - 2 * f->dy;
		}
		coord[0]++;
	}
}

void	g_negative_high(t_f *f, t_nmbs nbr1, t_nmbs nbr2)
{
	int	coord[2];
	int	c;

	c = -1;
	f->dx = nbr2.x_mod - nbr1.x_mod;
	f->dy = nbr2.y_mod - nbr1.y_mod;
	f->dd = 2 * f->dy - f->dx;
	coord[0] = nbr2.x_mod;
	coord[1] = nbr2.y_mod;
	while ((coord[1] < nbr1.y_mod) && nbr1.grd[++c])
	{
		if (f->dd >= 0)
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[c]);
			coord[0]--;
			f->dd = f->dd + 2 * f->dx + 2 * f->dy;
		}
		else
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[c]);
			f->dd = f->dd + 2 * f->dx;
		}
		coord[1]++;
	}
}
