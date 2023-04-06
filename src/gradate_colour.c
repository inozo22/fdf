/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradate_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:00:27 by nimai             #+#    #+#             */
/*   Updated: 2023/04/06 17:17:37 by nimai            ###   ########.fr       */
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

void	gradiente(int start, int end, t_fdf *fdf, int j, int i)
{
	float	increment[3];
	int		tmp[3];
	int		c;
	int		newcolour;

	c = 0;
	printf("Line: %d, start: %x, end: %x\n", __LINE__, start, end);
	printf("Line: %d, len: %d\n", __LINE__, fdf->n[j][i].len);
	increment[0] = (float)((R(end)) - (R(start))) / (float)fdf->n[j][i].len;
	increment[1] = (float)((G(end)) - (G(start))) / (float)fdf->n[j][i].len;
	increment[2] = (float)((B(end)) - (B(start))) / (float)fdf->n[j][i].len;
//	printf("Line: %d, increment[0]: %f\n", __LINE__, increment[0]);
//	printf("Line: %d, increment[1]: %f\n", __LINE__, increment[1]);
//	printf("iLine: %d, ncrement[2]: %f\n", __LINE__, increment[2]);
	while (c < fdf->n[j][i].len)
	{
/* 		increment[0] = (float)((R(end)) - (R(start))) / (float)fdf->n[j][i].len;
		increment[1] = (float)((G(end)) - (G(start))) / (float)fdf->n[j][i].len;
		increment[2] = (float)((B(end)) - (B(start))) / (float)fdf->n[j][i].len;
		printf("Line: %d, increment[0]: %f\n", __LINE__, increment[0]);
		printf("Line: %d, increment[1]: %f\n", __LINE__, increment[1]);
		printf("iLine: %d, ncrement[2]: %f\n", __LINE__, increment[2]); */

		tmp[0] = (R(start)) + round_nb(c * increment[0]);
		tmp[1] = (G(start)) + round_nb(c * increment[1]);
		tmp[2] = (B(start)) + round_nb(c * increment[2]);

		newcolour = RGB(tmp[0], tmp[1], tmp[2]);
		fdf->n[j][i].grd[c] = newcolour;
//		printf("0:%d, 1:%d, 2:%d\nnewcolour: %x\n", tmp[0], tmp[1], tmp[2], newcolour);
//		printf("fdf->n[j][i].grd[%d]: %x\n", c, fdf->n[j][i].grd[c]);
		c++;
	}
}

void	u_gradate_colour(t_fdf *fdf, int j, int i, t_map *map)
{
	int	start;
	int	end;

	if (fdf->n[j][i].colour > fdf->n[j + 1][i].colour)
	{
		start = fdf->n[j + 1][i].colour;
		end = fdf->n[j][i].colour;
	//	printf("Line: %d, File: %s, fdf->n[j + 1][i].len: %d\n", __LINE__, __FILE__, fdf->n[j + 1][i].len);
		gradiente(start, end, fdf, j, i);
		g_get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i]);
	}
	else
	{
		end = fdf->n[j + 1][i].colour;
		start = fdf->n[j][i].colour;
	//	printf("Line: %d, File: %s, fdf->n[j + 1][i].len: %d\n", __LINE__, __FILE__, fdf->n[j + 1][i].len);
		gradiente(start, end, fdf, j, i);
		g_get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i]);
	}
}
