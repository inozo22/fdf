/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradate_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:00:27 by nimai             #+#    #+#             */
/*   Updated: 2023/05/01 13:17:14 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	u_gradate_colour(t_f *f, int j, int i)
{
	if (f->n[j][i].colour > f->n[j + 1][i].colour)
	{
		gradiente(f->n[j + 1][i].colour, f->n[j][i].colour, f);
		g_get_slope(f, f->n[j][i], f->n[j + 1][i]);
	}
	else
	{
		gradiente(f->n[j][i].colour, f->n[j + 1][i].colour, f);
		g_get_slope(f, f->n[j][i], f->n[j + 1][i]);
	}
}

void	r_gradate_colour(t_f *f, int j, int i)
{
	if (f->n[j][i].colour > f->n[j][i + 1].colour)
	{
		gradiente(f->n[j][i + 1].colour, f->n[j][i].colour, f);
		g_get_slope(f, f->n[j][i], f->n[j][i + 1]);
	}
	else
	{
		gradiente(f->n[j][i].colour, f->n[j][i + 1].colour, f);
		g_get_slope(f, f->n[j][i], f->n[j][i + 1]);
	}
}

void	ur_gradate_colour(t_f *f, int j, int i)
{
	if (f->n[j][i].colour > f->n[j + 1][i + 1].colour)
	{
		gradiente(f->n[j + 1][i + 1].colour, f->n[j][i].colour, f);
		g_get_slope(f, f->n[j][i], f->n[j + 1][i + 1]);
	}
	else
	{
		gradiente(f->n[j][i].colour, f->n[j + 1][i + 1].colour, f);
		g_get_slope(f, f->n[j][i], f->n[j + 1][i + 1]);
	}
}
