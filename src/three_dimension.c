/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_dimension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:25:38 by nimai             #+#    #+#             */
/*   Updated: 2023/05/01 13:17:31 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	swap_nbr(t_f *f, t_nmbs *nbr1, t_nmbs *nbr2)
{
	t_nmbs	tmp;

	tmp.x_mod = nbr1->x_mod;
	tmp.y_mod = nbr1->y_mod;
	nbr1->x_mod = nbr2->x_mod;
	nbr1->y_mod = nbr2->y_mod;
	nbr2->x_mod = tmp.x_mod;
	nbr2->y_mod = tmp.y_mod;
	get_slope(f, *nbr1, *nbr2);
	tmp.x_mod = nbr1->x_mod;
	tmp.y_mod = nbr1->y_mod;
	nbr1->x_mod = nbr2->x_mod;
	nbr1->y_mod = nbr2->y_mod;
	nbr2->x_mod = tmp.x_mod;
	nbr2->y_mod = tmp.y_mod;
}

void	get_slope(t_f *f, t_nmbs nbr1, t_nmbs nbr2)
{
	int	dx;
	int	dy;
	int	dd;

	dx = nbr2.x_mod - nbr1.x_mod;
	dy = nbr2.y_mod - nbr1.y_mod;
	dd = abs(dx) - abs(dy);
	if (dx < 0)
		swap_nbr(f, &nbr1, &nbr2);
	else if (dy < 0 && dd < 0)
		negative_high(f, nbr1, nbr2);
	else if (dy < 0 && dd >= 0)
		negative_low(f, nbr1, nbr2);
	else if (dy >= 0 && dd >= 0)
		positive_low(f, nbr1, nbr2);
	else if (dy > 0 && dd < 0)
		positive_high(f, nbr1, nbr2);
}

void	check_slope_colour(t_f *f, int j, int i)
{
	get_slope(f, f->n[j][i], f->n[j + 1][i]);
	if (f->n[j][i].colour != f->n[j + 1][i].colour)
		u_gradate_colour(f, j, i);
	get_slope(f, f->n[j][i], f->n[j][i + 1]);
	if (f->n[j][i].colour != f->n[j][i + 1].colour)
		r_gradate_colour(f, j, i);
	get_slope(f, f->n[j][i], f->n[j + 1][i + 1]);
	if (f->n[j][i].colour != f->n[j + 1][i + 1].colour)
		ur_gradate_colour(f, j, i);
}

void	check_slope_colour_edge(t_f *f, int j, int i)
{
	if (i == (f->row_len - 1) && j != (f->column - 1))
	{
		get_slope(f, f->n[j][i], f->n[j + 1][i]);
		if (f->n[j][i].colour != f->n[j + 1][i].colour)
			u_gradate_colour(f, j, i);
	}
	else if (i != (f->row_len - 1) && j == (f->column - 1))
	{
		get_slope(f, f->n[j][i], f->n[j][i + 1]);
		if (f->n[j][i].colour != f->n[j][i + 1].colour)
			r_gradate_colour(f, j, i);
	}
}

void	three_dimension(t_f *f)
{
	int	i;
	int	j;

	j = -1;
	while (++j < f->column)
	{
		i = -1;
		while (++i < f->row_len)
		{
			f->pwd_j = j;
			f->pwd_i = i;
			if (i != (f->row_len - 1) && j != (f->column - 1))
				check_slope_colour(f, j, i);
			else
				check_slope_colour_edge(f, j, i);
		}
	}
}
