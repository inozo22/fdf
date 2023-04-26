/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_positions_keep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:09:34 by nimai             #+#    #+#             */
/*   Updated: 2023/04/25 17:53:24 by nimai            ###   ########.fr       */
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
	if (nbr1.grd[0] > nbr1.grd[nbr1.len]/*  && nbr1.colour < nbr2.colour && f->flag == 0 */)
	{
		while ((coord[0] < nbr2.x_mod))
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
			c++;
		}
	}
/* 	else if (nbr1.grd[0] < nbr1.grd[nbr1.len] && nbr1.colour < nbr2.colour && f->flag == 0)
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
		}
	}*/
/* 	else
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
	} */
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
	} */
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
	if (nbr1.grd[0] > nbr1.grd[nbr1.len]&& nbr1.colour > nbr2.colour && f->flag == 0)//there is no swap
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
	else if (nbr1.grd[0] < nbr1.grd[nbr1.len]&& nbr1.colour > nbr2.colour && f->flag == 0)//there is no swap
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
	else if (nbr1.grd[0] > nbr1.grd[nbr1.len] && nbr1.colour < nbr2.colour && f->flag == 1)//ayashii hasta aqui, 0425 from here
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
/* 	else if (nbr1.grd[0] > nbr1.grd[nbr1.len] && nbr1.colour < nbr2.colour && f->flag == 1)//koreha kann
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
}





///gomi

/*  void	g_positive_high_b(t_f *f, t_nmbs nbr1, t_nmbs nbr2)
{
	int		c;
	int		i;
	t_nmbs	tmp;

	tmp = nbr1;
	i = nbr1.len;
	c = 0;
	if (/* nbr1.grd[0] != nbr1.grd[nbr1.len]&&  /*nbr1.colour > nbr2.colour && f->flag == 0)*///there is no swap
	/*{
		while (i >= 0)
		{
			nbr1.grd[c] = tmp.grd[i];
			printf("pwd: j: %d i: %d\ncolour[%d]: %x\n", f->pwd_j, f->pwd_i, c, nbr1.grd[c]);
			c++;
			i--;
		}
	}
	g_positive_high(f, nbr1, nbr2); */
/* 	else if (nbr1.grd[0] < nbr1.grd[nbr1.len]&& nbr1.colour > nbr2.colour && f->flag == 0)//there is no swap
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
/* 	else
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
	}  */
//}
/*