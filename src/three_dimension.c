/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_dimension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:25:38 by nimai             #+#    #+#             */
/*   Updated: 2023/03/20 17:32:41 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	get_slope(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2);

static void	swap_nbr(t_fdf *fdf, t_map *map, t_nmbs *nbr1, t_nmbs *nbr2)
{
	t_nmbs	tmp;

	tmp.x = nbr1->x_mod;
	tmp.y = nbr1->y_mod;
	nbr1->x_mod = nbr2->x_mod;
	nbr1->y_mod = nbr2->y_mod;
	nbr2->x_mod = tmp.x;
	nbr2->y_mod = tmp.y;
	get_slope(fdf, map, *nbr1, *nbr2);
	tmp.x = nbr1->x_mod;
	tmp.y = nbr1->y_mod;
	nbr1->x_mod = nbr2->x_mod;
	nbr1->y_mod = nbr2->y_mod;
	nbr2->x_mod = tmp.x;
	nbr2->y_mod = tmp.y;
}

void	get_slope(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2)
{
	long	dx;
	long	dy;
	long	dd;

	dx = nbr2.x_mod - nbr1.x_mod;
	dy = nbr2.y_mod - nbr1.y_mod;
	dd = labs(dx) - labs(dy);
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

void	three_dimension(t_fdf *fdf, t_map *map)
{
	long	i;
	long	j;

	j = -1;
	while (++j < fdf->column)
	{
		i = -1;
		while (++i < fdf->row_len)
		{
			if (i != (fdf->row_len - 1) && j != (fdf->column - 1))
			{
				get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i]);
				get_slope(fdf, map, fdf->n[j][i], fdf->n[j][i + 1]);
				get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i + 1]);
			}
			else if (i == (fdf->row_len - 1) && j != (fdf->column - 1))
			{
				get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i]);
			}
			else if (i != (fdf->row_len - 1) && j == (fdf->column - 1))
			{
				get_slope(fdf, map, fdf->n[j][i], fdf->n[j][i + 1]);
			}
		}
	}
}
