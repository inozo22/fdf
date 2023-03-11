/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:52:18 by nimai             #+#    #+#             */
/*   Updated: 2023/03/11 21:30:43 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//t_line	init_row

t_fdf	*init_fdf(int fd, t_fdf *fdf)
{
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		exit (fdf_error(1));//error without memory
//	fdf->row = init_row(fd, fdf->row);
//	fdf->column = init_column(fd, fdf->column);	
}

void	fdf(int fd)
{
	t_fdf	*fdf;

	fdf = init_fdf(fd, fdf);

}
