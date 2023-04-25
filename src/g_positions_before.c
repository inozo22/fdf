/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_positions_before.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:09:34 by nimai             #+#    #+#             */
/*   Updated: 2023/04/25 18:40:39 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	g_positive_low_b(t_f *f, t_nmbs nbr1, t_nmbs nbr2)
{
	int		c;
	int		i;
	t_nmbs	tmp;

	tmp = nbr1;
	i = nbr1.len;
	c = 0;
	if (nbr1.grd[0] > nbr1.grd[i] && nbr1.colour < nbr2.colour && f->flag == 0)
	{
		while (i >= 0)
		{
			nbr1.grd[c] = tmp.grd[i];
			c++;
			i--;
		}
	}
	g_positive_low(f, nbr1, nbr2);
}

//なんでかわからないけど、条件を反転したらできた。なんでかはわからん。
void	g_positive_high_b(t_f *f, t_nmbs nbr1, t_nmbs nbr2)
{
	int		c;
	int		i;
	t_nmbs	tmp;

	tmp = nbr1;
	i = nbr1.len;
	c = 0;
	if (nbr1.grd[0] != nbr1.grd[i] && nbr1.colour > \
	nbr2.colour && f->flag == 0)
	{
		g_positive_high(f, nbr1, nbr2);
	}
	else
	{
		while (i >= 0)
		{
			nbr1.grd[c] = tmp.grd[i];
			c++;
			i--;
		}
		g_positive_high(f, nbr1, nbr2);
	}
}

void	g_negative_low_b(t_f *f, t_nmbs nbr1, t_nmbs nbr2)
{
	int		c;
	int		i;
	t_nmbs	tmp;

	tmp = nbr1;
	i = nbr1.len;
	c = 0;
	if (nbr1.grd[0] > nbr1.grd[nbr1.len] && f->flag == 1)
	{
		g_negative_low(f, nbr1, nbr2);
	}
	else
	{
		while (i >= 0)
		{
			nbr1.grd[c] = tmp.grd[i];
			c++;
			i--;
		}
		g_negative_low(f, nbr1, nbr2);
	}
}

void	g_negative_high_b(t_f *f, t_nmbs nbr1, t_nmbs nbr2)
{
	int		c;
	int		i;
	t_nmbs	tmp;

	tmp = nbr1;
	i = nbr1.len;
	c = 0;
	if (nbr1.grd[0] > nbr1.grd[nbr1.len] && nbr1.colour > \
	nbr2.colour && f->flag == 1)
	{
		g_negative_high(f, nbr1, nbr2);
	}
	else
	{
		while (i >= 0)
		{
			nbr1.grd[c] = tmp.grd[i];
			c++;
			i--;
		}
		g_negative_high(f, nbr1, nbr2);
	}
}
