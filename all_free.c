/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:11:18 by nimai             #+#    #+#             */
/*   Updated: 2023/03/14 17:01:45 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**strs_clear(char **tab, long i)
{
	while (i > 0)
	{
		i--;
		free (tab[i]);
	}
	free (tab);
	return (NULL);
}

void	all_free(t_fdf *fdf)
{
//	if (fdf->strs)//maybe I can omit this, check when I finish all functions
//		strs_clear(fdf->strs, fdf->row_len);
	
	free (fdf);
}

