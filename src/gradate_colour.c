/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradate_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:00:27 by nimai             #+#    #+#             */
/*   Updated: 2023/04/07 15:33:18 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
