/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradiente.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:00:27 by nimai             #+#    #+#             */
/*   Updated: 2023/04/24 18:13:59 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	g_swap_nbr(t_f *f, t_nmbs *nbr1, t_nmbs *nbr2)
{
	t_nmbs	tmp;

	tmp.x_mod = nbr1->x_mod;
	tmp.y_mod = nbr1->y_mod;
	nbr1->x_mod = nbr2->x_mod;
	nbr1->y_mod = nbr2->y_mod;
	nbr2->x_mod = tmp.x_mod;
	nbr2->y_mod = tmp.y_mod;
	g_get_slope(f, *nbr1, *nbr2);
	tmp.x_mod = nbr1->x_mod;
	tmp.y_mod = nbr1->y_mod;
	nbr1->x_mod = nbr2->x_mod;
	nbr1->y_mod = nbr2->y_mod;
	nbr2->x_mod = tmp.x_mod;
	nbr2->y_mod = tmp.y_mod;
	f->flag = 0;
}

void	g_get_slope(t_f *f, t_nmbs nbr1, t_nmbs nbr2)
{
	int	dx;
	int	dy;
	int	dd;

	dx = nbr2.x_mod - nbr1.x_mod;
	dy = nbr2.y_mod - nbr1.y_mod;
	dd = abs(dx) - abs(dy);
	if (dx < 0)
	{
		f->flag = 1;
		g_swap_nbr(f, &nbr1, &nbr2);
	}
	else if (dy < 0 && dd < 0)
		g_negative_high(f, nbr1, nbr2);
	else if (dy < 0 && dd >= 0)
		g_negative_low(f, nbr1, nbr2);
	else if (dy >= 0 && dd >= 0)
		g_positive_low(f, nbr1, nbr2);
	else if (dy > 0 && dd < 0)
		g_positive_high(f, nbr1, nbr2);
}

int	round_nb(float nb)
{
	int	ret;

	ret = (int)nb;
	if (nb - ret >= .5)
		ret++;
	return (ret);
}

void	gradiente(int start, int end, t_f *f)
{
	float	increment[3];
	int		tmp[3];
	int		c;

	c = 0;
	increment[0] = (float)(((end >> 16)) - ((start >> 16))) / \
	(float)f->n[f->pwd_j][f->pwd_i].len;
	increment[1] = (float)(((end >> 8) & 0xFF) - ((start >> 8) & 0xFF)) / \
	(float)f->n[f->pwd_j][f->pwd_i].len;
	increment[2] = (float)(((end) & 0xFF) - ((start) & 0xFF)) / \
	(float)f->n[f->pwd_j][f->pwd_i].len;
	while (c < f->n[f->pwd_j][f->pwd_i].len)
	{
		tmp[0] = ((start >> 16)) + round_nb(c * increment[0]);
		tmp[1] = ((start >> 8) & 0xFF) + round_nb(c * increment[1]);
		tmp[2] = ((start) & 0xFF) + round_nb(c * increment[2]);
		f->n[f->pwd_j][f->pwd_i].grd[c] = (tmp[0] << 16) + \
		(tmp[1] << 8) + (tmp[2]);
		c++;
	}
}
