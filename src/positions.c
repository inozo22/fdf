/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:09:34 by nimai             #+#    #+#             */
/*   Updated: 2023/04/18 13:43:45 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	positive_low(t_f *f, t_nmbs nbr1, t_nmbs nbr2)
{
	int	coord[2];

	f->n[f->pwd_j][f->pwd_i].len = 0;
	f->dx = nbr2.x_mod - nbr1.x_mod;
	f->dy = nbr2.y_mod - nbr1.y_mod;
	f->dd = 2 * f->dy - f->dx;
	coord[0] = nbr1.x_mod;
	coord[1] = nbr1.y_mod;
	while (coord[0] < nbr2.x_mod)
	{
		if (f->dd >= 0)
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.colour);
			coord[1]++;
			f->dd = f->dd + 2 * f->dy - 2 * f->dx;
		}
		else
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.colour);
			f->dd = f->dd + 2 * f->dy;
		}
		coord[0]++;
		f->n[f->pwd_j][f->pwd_i].len++;
	}
}

void	positive_high(t_f *f, t_nmbs nbr1, t_nmbs nbr2)
{
	int	coord[2];

	f->n[f->pwd_j][f->pwd_i].len = 0;
	f->dx = nbr2.x_mod - nbr1.x_mod;
	f->dy = nbr2.y_mod - nbr1.y_mod;
	f->dd = 2 * f->dx - f->dy;
	coord[0] = nbr1.x_mod;
	coord[1] = nbr1.y_mod;
	while (coord[1] < nbr2.y_mod)
	{
		if (f->dd >= 0)
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.colour);
			coord[0]++;
			f->dd = f->dd + 2 * f->dx - 2 * f->dy;
		}
		else
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.colour);
			f->dd = f->dd + 2 * f->dx;
		}
		coord[1]++;
		f->n[f->pwd_j][f->pwd_i].len++;
	}
}

void	negative_low(t_f *f, t_nmbs nbr1, t_nmbs nbr2)
{
	int	coord[2];

	f->n[f->pwd_j][f->pwd_i].len = 0;
	f->dx = nbr2.x_mod - nbr1.x_mod;
	f->dy = nbr2.y_mod - nbr1.y_mod;
	f->dd = 2 * f->dy - f->dx;
	coord[0] = nbr1.x_mod;
	coord[1] = nbr1.y_mod;
	while (coord[0] < nbr2.x_mod)
	{
		if (f->dd >= 0)
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.colour);
			coord[1]--;
			f->dd = f->dd - 2 * f->dy - 2 * f->dx;
		}
		else
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.colour);
			f->dd = f->dd - 2 * f->dy;
		}
		coord[0]++;
		f->n[f->pwd_j][f->pwd_i].len++;
	}
}

void	negative_high(t_f *f, t_nmbs nbr1, t_nmbs nbr2)
{
	int	coord[2];

	f->n[f->pwd_j][f->pwd_i].len = 0;
	f->dx = nbr2.x_mod - nbr1.x_mod;
	f->dy = nbr2.y_mod - nbr1.y_mod;
	f->dd = 2 * f->dy - f->dx;
	coord[0] = nbr2.x_mod;
	coord[1] = nbr2.y_mod;
	while (coord[1] < nbr1.y_mod)
	{
		if (f->dd >= 0)
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.colour);
			coord[0]--;
			f->dd = f->dd + 2 * f->dx + 2 * f->dy;
		}
		else
		{
			my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.colour);
			f->dd = f->dd + 2 * f->dx;
		}
		coord[1]++;
		f->n[f->pwd_j][f->pwd_i].len++;
	}
}
