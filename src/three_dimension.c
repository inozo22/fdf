/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_dimension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:25:38 by nimai             #+#    #+#             */
/*   Updated: 2023/04/07 14:01:46 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	swap_nbr(t_fdf *fdf, t_map *map, t_nmbs *nbr1, t_nmbs *nbr2)
{
	t_nmbs	tmp;

	tmp.x_mod = nbr1->x_mod;
	tmp.y_mod = nbr1->y_mod;
	nbr1->x_mod = nbr2->x_mod;
	nbr1->y_mod = nbr2->y_mod;
	nbr2->x_mod = tmp.x_mod;
	nbr2->y_mod = tmp.y_mod;
	get_slope(fdf, map, *nbr1, *nbr2);
	tmp.x_mod = nbr1->x_mod;
	tmp.y_mod = nbr1->y_mod;
	nbr1->x_mod = nbr2->x_mod;
	nbr1->y_mod = nbr2->y_mod;
	nbr2->x_mod = tmp.x_mod;
	nbr2->y_mod = tmp.y_mod;
}

void	get_slope(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2)
{
	int	dx;
	int	dy;
	int	dd;

	dx = nbr2.x_mod - nbr1.x_mod;
	dy = nbr2.y_mod - nbr1.y_mod;
	dd = abs(dx) - abs(dy);
	if (dx < 0)
		swap_nbr(fdf, map, &nbr1, &nbr2);
	else if (dy < 0 && dd < 0)
		negative_high(fdf, map, nbr1, nbr2);
	else if (dy < 0 && dd >= 0)
		negative_low(fdf, map, nbr1, nbr2);
	else if (dy >= 0 && dd >= 0)
		positive_low(fdf, map, nbr1, nbr2);
	else if (dy > 0 && dd < 0)
		positive_high(fdf, map, nbr1, nbr2);
}

void	check_slope_colour(t_fdf *fdf, t_map *map, int j, int i)
{
	get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i]);
	if (fdf->n[j][i].colour != fdf->n[j + 1][i].colour)
		u_gradate_colour(fdf, j, i, map);
	get_slope(fdf, map, fdf->n[j][i], fdf->n[j][i + 1]);
	if (fdf->n[j][i].colour != fdf->n[j][i + 1].colour)
		r_gradate_colour(fdf, j, i, map);
	get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i + 1]);
	if (fdf->n[j][i].colour != fdf->n[j + 1][i + 1].colour)
		ur_gradate_colour(fdf, j, i, map);
}

void	check_slope_colour_edge(t_fdf *fdf, t_map *map, int j, int i)
{
	if (i == (fdf->row_len - 1) && j != (fdf->column - 1))
	{
		get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i]);
		if (fdf->n[j][i].colour != fdf->n[j + 1][i].colour)
			u_gradate_colour(fdf, j, i, map);
	}
	else if (i != (fdf->row_len - 1) && j == (fdf->column - 1))
	{
		get_slope(fdf, map, fdf->n[j][i], fdf->n[j][i + 1]);
		if (fdf->n[j][i].colour != fdf->n[j][i + 1].colour)
			r_gradate_colour(fdf, j, i, map);
	}
}

void	three_dimension(t_fdf *fdf, t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < fdf->column)
	{
		i = -1;
		while (++i < fdf->row_len)
		{
			fdf->pwd_j = j;
			fdf->pwd_i = i;
			if (i != (fdf->row_len - 1) && j != (fdf->column - 1))
				check_slope_colour(fdf, map, j, i);
			else
				check_slope_colour_edge(fdf, map, j, i);
		}
	}
}
