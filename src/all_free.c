/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:11:18 by nimai             #+#    #+#             */
/*   Updated: 2023/04/18 15:58:55 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	**strs_clear(char **tab, int i)
{
	while (i > 0)
	{
		i--;
		free (tab[i]);
	}
	free (tab);
	return (NULL);
}

/* void	f_free(t_f *f)
{
	if (f->strs)
		strs_clear(f->strs, f->column);
	free (f);
} */

void	all_free(t_f *f)
{
	if (&(f->map->vars))
		free (&f->map->vars);
/* 	if (f->map != (void *)0) */
//	free (f->map);
/* 	if (f->strs)
		strs_clear(f->strs, f->column); */
	free(f);
}
