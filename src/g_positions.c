/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_positions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:09:34 by nimai             #+#    #+#             */
/*   Updated: 2023/04/24 18:50:17 by nimai            ###   ########.fr       */
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
	if (nbr1.grd[0] < nbr1.grd[nbr1.len] && f->flag == 1)
	{
		while ((coord[0] < nbr2.x_mod) && nbr1.len >= 0)
		{
			if (f->dd >= 0)
			{
				my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[nbr1.len]);
				coord[1]++;
				f->dd = f->dd + 2 * f->dy - 2 * f->dx;
			}
			else
			{
				my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[nbr1.len]);
				f->dd = f->dd + 2 * f->dy;
			}
			coord[0]++;
			nbr1.len--;
		}		
	}
	else
	{
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
/* 	else
	{
		while ((coord[0] < nbr2.x_mod) && nbr1.len >= 0)
		{
			if (f->dd >= 0)
			{
				my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[nbr1.len]);
				coord[1]++;
				f->dd = f->dd + 2 * f->dy - 2 * f->dx;
			}
			else
			{
				my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[nbr1.len]);
				f->dd = f->dd + 2 * f->dy;
			}
			coord[0]++;
			nbr1.len--;
		}
	}
 */
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
	if (nbr1.grd[0] < nbr1.grd[nbr1.len] && f->flag == 1)
	{
		while ((coord[1] < nbr2.y_mod) && nbr1.len >= 0)
		{
			if (f->dd >= 0)
			{
				my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[nbr1.len]);
				coord[0]++;
				f->dd = f->dd + 2 * f->dx - 2 * f->dy;
			}
			else
			{
				my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[nbr1.len]);
				f->dd = f->dd + 2 * f->dx;
			}
			coord[1]++;
			nbr1.len--;
		}		
	}
	else
	{
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
/* 	else
	{
		while ((coord[1] < nbr2.y_mod) && nbr1.len >= 0)
		{
			if (f->dd >= 0)
			{
				my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[nbr1.len]);
				coord[0]++;
				f->dd = f->dd + 2 * f->dx - 2 * f->dy;
			}
			else
			{
				my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[nbr1.len]);
				f->dd = f->dd + 2 * f->dx;
			}
			coord[1]++;
			nbr1.len--;
		}
	} */

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
	if (nbr1.grd[0] > nbr1.grd[nbr1.len] && nbr1.colour > nbr2.colour && f->flag == 1)//ayashii hasta aqui, 0425 from here
	{
		while ((coord[0] < nbr2.x_mod) && nbr1.len >= 0)
		{
			if (f->dd >= 0)
			{
				my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[nbr1.len]);
				coord[1]--;
				f->dd = f->dd - 2 * f->dy - 2 * f->dx;
			}
			else
			{
				my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[nbr1.len]);
				f->dd = f->dd - 2 * f->dy;
			}
			coord[0]++;
			nbr1.len--;
		}		
	}
	else
	{
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
/* 	else
	{
		while ((coord[0] < nbr2.x_mod) && nbr1.len >= 0)
		{
			if (f->dd >= 0)
			{
				my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[nbr1.len]);
				coord[1]--;
				f->dd = f->dd - 2 * f->dy - 2 * f->dx;
			}
			else
			{
				my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[nbr1.len]);
				f->dd = f->dd - 2 * f->dy;
			}
			coord[0]++;
			nbr1.len--;
		}
	} */

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
	if (nbr1.grd[0] > nbr1.grd[nbr1.len] && nbr1.colour > nbr2.colour && f->flag == 1)//ayashii
	{
		while ((coord[1] < nbr1.y_mod) && nbr1.len >= 0)
		{
			if (f->dd >= 0)
			{
				my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[nbr1.len]);
				coord[0]--;
				f->dd = f->dd + 2 * f->dx + 2 * f->dy;
			}
			else
			{
				my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[nbr1.len]);
				f->dd = f->dd + 2 * f->dx;
			}
			coord[1]++;
			nbr1.len--;
		}
	}
	else
	{
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

/* 	if (f->flag == 0)
	{
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
	else
	{
		while ((coord[1] < nbr1.y_mod) && nbr1.len >= 0)
		{
			if (f->dd >= 0)
			{
				my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[nbr1.len]);
				coord[0]--;
				f->dd = f->dd + 2 * f->dx + 2 * f->dy;
			}
			else
			{
				my_mlx_pixel_put(&f->map->data, coord[0], coord[1], nbr1.grd[nbr1.len]);
				f->dd = f->dd + 2 * f->dx;
			}
			coord[1]++;
			nbr1.len--;
		}
	} */
}
