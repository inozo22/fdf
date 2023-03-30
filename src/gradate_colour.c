/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradate_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:00:27 by nimai             #+#    #+#             */
/*   Updated: 2023/03/30 16:51:09 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	gradiente(int start, int end, t_fdf *fdf, int j, int i)
{
	float	increment[3];
	int		tmp[3];
	int		c;

	c = 0;
	printf("Line: %d, len: %d\n", __LINE__, fdf->n[j][i].len);
	while (c < fdf->n[j][i].len)
	{
		increment[0] = (float)((R(end)) - (R(start))) / (float)fdf->n[j][i].len;
		increment[1] = (float)((G(end)) - (G(start))) / (float)fdf->n[j][i].len;
		increment[2] = (float)((B(end)) - (B(start))) / (float)fdf->n[j][i].len;
		printf("Line: %d, increment[0]: %f\n", __LINE__, increment[0]);
		printf("Line: %d, increment[1]: %f\n", __LINE__, increment[1]);
		printf("iLine: %d, ncrement[2]: %f\n", __LINE__, increment[2]);
		exit (1);
	//	fdf->n[j][i].grd[c] = 
		c++;
	}






//	fdf->n[j][i].grd[c] = 


}

void	u_gradate_colour(t_fdf *fdf, int j, int i, t_map *map)
{
	int	start;
	int	end;

	if (fdf->n[j][i].colour > fdf->n[j + 1][i].colour)
	{
		start = fdf->n[j + 1][i].colour;
		end = fdf->n[j][i].colour;
		printf("Line: %d, fdf->n[j][i].len: %d\n", __LINE__, fdf->n[j][i].len);
		gradiente(start, end, fdf, j, i);
	}
	else
	{
		end = fdf->n[j + 1][i].colour;
		start = fdf->n[j][i].colour;

	}
}
