/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_positions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:09:34 by nimai             #+#    #+#             */
/*   Updated: 2023/04/26 09:44:10 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	g_positive_low(t_f *f, t_nmbs n1, t_nmbs n2)
{
	int	coord[2];

	f->dx = n2.x_mod - n1.x_mod;
	f->dy = n2.y_mod - n1.y_mod;
	f->dd = 2 * f->dy - f->dx;
	coord[0] = n1.x_mod;
	coord[1] = n1.y_mod;
	while ((coord[0] < n2.x_mod) && n1.len >= 0)
	{
		if (f->dd >= 0)
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], n1.grd[n1.len]);
			coord[1]++;
			f->dd = f->dd + 2 * f->dy - 2 * f->dx;
		}
		else
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], n1.grd[n1.len]);
			f->dd = f->dd + 2 * f->dy;
		}
		coord[0]++;
		n1.len--;
	}
}

void	g_positive_high(t_f *f, t_nmbs n1, t_nmbs n2)
{
	int	coord[2];

	f->dx = n2.x_mod - n1.x_mod;
	f->dy = n2.y_mod - n1.y_mod;
	f->dd = 2 * f->dx - f->dy;
	coord[0] = n1.x_mod;
	coord[1] = n1.y_mod;
	while ((coord[1] < n2.y_mod) && n1.len >= 0)
	{
		if (f->dd >= 0)
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], n1.grd[n1.len]);
			coord[0]++;
			f->dd = f->dd + 2 * f->dx - 2 * f->dy;
		}
		else
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], n1.grd[n1.len]);
			f->dd = f->dd + 2 * f->dx;
		}
		coord[1]++;
		n1.len--;
	}
}

void	g_negative_low(t_f *f, t_nmbs n1, t_nmbs n2)
{
	int	coord[2];

	f->dx = n2.x_mod - n1.x_mod;
	f->dy = n2.y_mod - n1.y_mod;
	f->dd = 2 * f->dy - f->dx;
	coord[0] = n1.x_mod;
	coord[1] = n1.y_mod;
	while ((coord[0] < n2.x_mod) && n1.len >= 0)
	{
		if (f->dd >= 0)
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], n1.grd[n1.len]);
			coord[1]--;
			f->dd = f->dd - 2 * f->dy - 2 * f->dx;
		}
		else
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], n1.grd[n1.len]);
			f->dd = f->dd - 2 * f->dy;
		}
		coord[0]++;
		n1.len--;
	}
}

void	g_negative_high(t_f *f, t_nmbs n1, t_nmbs n2)
{
	int	coord[2];

	f->dx = n2.x_mod - n1.x_mod;
	f->dy = n2.y_mod - n1.y_mod;
	f->dd = 2 * f->dy - f->dx;
	coord[0] = n2.x_mod;
	coord[1] = n2.y_mod;
	while ((coord[1] < n1.y_mod) && n1.len >= 0)
	{
		if (f->dd >= 0)
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], n1.grd[n1.len]);
			coord[0]--;
			f->dd = f->dd + 2 * f->dx + 2 * f->dy;
		}
		else
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], n1.grd[n1.len]);
			f->dd = f->dd + 2 * f->dx;
		}
		coord[1]++;
		n1.len--;
	}
}
