/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradate_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:00:27 by nimai             #+#    #+#             */
/*   Updated: 2023/04/11 11:18:00 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//gradate_colour puede ser una function?
void	u_gradate_colour(t_fdf *fdf, int j, int i, t_map *map)
{
	if (fdf->n[j][i].colour > fdf->n[j + 1][i].colour)
	{
		gradiente(fdf->n[j + 1][i].colour, fdf->n[j][i].colour, fdf);
		g_get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i]);
	}
	else
	{
		gradiente(fdf->n[j][i].colour, fdf->n[j + 1][i].colour, fdf);
		g_get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i]);
	}
}

void	r_gradate_colour(t_fdf *fdf, int j, int i, t_map *map)
{
	if (fdf->n[j][i].colour > fdf->n[j][i + 1].colour)
	{
		gradiente(fdf->n[j][i + 1].colour, fdf->n[j][i].colour, fdf);
		g_get_slope(fdf, map, fdf->n[j][i], fdf->n[j][i + 1]);
	}
	else
	{
		gradiente(fdf->n[j][i].colour, fdf->n[j][i + 1].colour, fdf);
		g_get_slope(fdf, map, fdf->n[j][i], fdf->n[j][i + 1]);
	}
}

void	ur_gradate_colour(t_fdf *fdf, int j, int i, t_map *map)
{
	if (fdf->n[j][i].colour > fdf->n[j + 1][i + 1].colour)
	{
		gradiente(fdf->n[j + 1][i + 1].colour, fdf->n[j][i].colour, fdf);
		g_get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i + 1]);
	}
	else
	{
		gradiente(fdf->n[j][i].colour, fdf->n[j + 1][i + 1].colour, fdf);
		g_get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i + 1]);
	}
}
