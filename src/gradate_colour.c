/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradate_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:00:27 by nimai             #+#    #+#             */
/*   Updated: 2023/04/07 14:59:48 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	g_swap_nbr(t_fdf *fdf, t_map *map, t_nmbs *nbr1, t_nmbs *nbr2)
{
	t_nmbs	tmp;

	tmp.x_mod = nbr1->x_mod;
	tmp.y_mod = nbr1->y_mod;
	nbr1->x_mod = nbr2->x_mod;
	nbr1->y_mod = nbr2->y_mod;
	nbr2->x_mod = tmp.x_mod;
	nbr2->y_mod = tmp.y_mod;
	g_get_slope(fdf, map, *nbr1, *nbr2);
	tmp.x_mod = nbr1->x_mod;
	tmp.y_mod = nbr1->y_mod;
	nbr1->x_mod = nbr2->x_mod;
	nbr1->y_mod = nbr2->y_mod;
	nbr2->x_mod = tmp.x_mod;
	nbr2->y_mod = tmp.y_mod;
}

void	g_get_slope(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2)
{
	int	dx;
	int	dy;
	int	dd;

	dx = nbr2.x_mod - nbr1.x_mod;
	dy = nbr2.y_mod - nbr1.y_mod;
	dd = abs(dx) - abs(dy);
	if (dx < 0)
		g_swap_nbr(fdf, map, &nbr1, &nbr2);
	else if (dy < 0 && dd < 0)
		g_negative_high(fdf, map, nbr1, nbr2);
	else if (dy < 0 && dd >= 0)
		g_negative_low(fdf, map, nbr1, nbr2);
	else if (dy >= 0 && dd >= 0)
		g_positive_low(fdf, map, nbr1, nbr2);
	else if (dy > 0 && dd < 0)
		g_positive_high(fdf, map, nbr1, nbr2);
}

int	round_nb(float nb)
{
	int	ret;

	ret = (int)nb;
	if (nb - ret >= .5)
		ret++;
	return (ret);
}

void	gradiente(int start, int end, t_fdf *fdf)
{
	float	increment[3];
	int		tmp[3];
	int		c;

	c = 0;
	increment[0] = (float)((R(end)) - (R(start))) / \
	(float)fdf->n[fdf->pwd_j][fdf->pwd_i].len;
	increment[1] = (float)((G(end)) - (G(start))) / \
	(float)fdf->n[fdf->pwd_j][fdf->pwd_i].len;
	increment[2] = (float)((B(end)) - (B(start))) / \
	(float)fdf->n[fdf->pwd_j][fdf->pwd_i].len;
	while (c < fdf->n[fdf->pwd_j][fdf->pwd_i].len)
	{
		tmp[0] = (R(start)) + round_nb(c * increment[0]);
		tmp[1] = (G(start)) + round_nb(c * increment[1]);
		tmp[2] = (B(start)) + round_nb(c * increment[2]);
		fdf->n[fdf->pwd_j][fdf->pwd_i].grd[c] = RGB(tmp[0], tmp[1], tmp[2]);
		c++;
	}
}

//gradate_colour puede ser una function?
void	u_gradate_colour(t_fdf *fdf, int j, int i, t_map *map)
{
	int	start;
	int	end;

	if (fdf->n[j][i].colour > fdf->n[j + 1][i].colour)
	{
		start = fdf->n[j + 1][i].colour;
		end = fdf->n[j][i].colour;
		gradiente(start, end, fdf);
		g_get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i]);
	}
	else
	{
		end = fdf->n[j + 1][i].colour;
		start = fdf->n[j][i].colour;
		gradiente(start, end, fdf);
		g_get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i]);
	}
}

void	r_gradate_colour(t_fdf *fdf, int j, int i, t_map *map)
{
	int	start;
	int	end;

	if (fdf->n[j][i].colour > fdf->n[j][i + 1].colour)
	{
		start = fdf->n[j][i + 1].colour;
		end = fdf->n[j][i].colour;
		gradiente(start, end, fdf);
		g_get_slope(fdf, map, fdf->n[j][i], fdf->n[j][i + 1]);
	}
	else
	{
		end = fdf->n[j][i + 1].colour;
		start = fdf->n[j][i].colour;
		gradiente(start, end, fdf);
		g_get_slope(fdf, map, fdf->n[j][i], fdf->n[j][i + 1]);
	}
}

void	ur_gradate_colour(t_fdf *fdf, int j, int i, t_map *map)
{
	int	start;
	int	end;

	if (fdf->n[j][i].colour > fdf->n[j + 1][i + 1].colour)
	{
		start = fdf->n[j + 1][i + 1].colour;
		end = fdf->n[j][i].colour;
		gradiente(start, end, fdf);
		g_get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i + 1]);
	}
	else
	{
		end = fdf->n[j + 1][i + 1].colour;
		start = fdf->n[j][i].colour;
		gradiente(start, end, fdf);
		g_get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i + 1]);
	}
}