/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_dimension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:25:38 by nimai             #+#    #+#             */
/*   Updated: 2023/03/21 16:50:43 by nimai            ###   ########.fr       */
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
	printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
}

void	get_slope(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2)
{
	int	dx;
	int	dy;
	int	dd;

	dx = nbr2.x_mod - nbr1.x_mod;
	dy = nbr2.y_mod - nbr1.y_mod;
	dd = abs(dx) - abs(dy);
	printf("where am I: %d, dx= %d, dy= %d, dd=%d\nfile: %s\n", __LINE__, dx, dy, dd, __FILE__);
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
//	printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
}

void	three_dimension(t_fdf *fdf, t_map *map)
{
	int	i;
	int	j;

	j = -1;
	printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
	printf("coumn: %ld\nrow_len: %ld\n", fdf->column, fdf->row_len);
	while (++j < fdf->column)
	{
		i = -1;
		while (++i < fdf->row_len)
		{
//			printf("where am I: %d, z= %ld\nfile: %s\n", __LINE__, fdf->n[j][i].z, __FILE__);
			if (i != (fdf->row_len - 1) && j != (fdf->column - 1))
			{
				printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
				get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i]);
				printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
				get_slope(fdf, map, fdf->n[j][i], fdf->n[j][i + 1]);
				printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
				get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i + 1]);
				printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
			}
			else if (i == (fdf->row_len - 1) && j != (fdf->column - 1))
			{
//				printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
				get_slope(fdf, map, fdf->n[j][i], fdf->n[j + 1][i]);
				printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
			}
			else if (i != (fdf->row_len - 1) && j == (fdf->column - 1))
			{
				get_slope(fdf, map, fdf->n[j][i], fdf->n[j][i + 1]);
				printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
			}
//			printf("where am I: %d, z= %ld\nfile: %s\n", __LINE__, fdf->n[j][i].z, __FILE__);
		}
//		printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
	}
//	printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
}
