/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:11:18 by nimai             #+#    #+#             */
/*   Updated: 2023/04/19 12:55:57 by nimai            ###   ########.fr       */
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

void	all_free(t_f *f)
{
	printf("Line: %d, f->map->vars.win: %p\n", __LINE__, &(f->map->vars.win));
	printf("f->map->vars: %p\n", &(f->map->vars));
	printf("f->map->data: %p\n", &(f->map->data));
	printf("Line: %d, f->map->data.endian: %p\n", __LINE__, &(f->map->data.endian));
	printf("f->map->mag: %p\n", &(f->map->mag));
	printf("f->map: %p\n", &(f->map));
	printf("f->n[0][0]: %p\n", (f->n[0][0]));
	printf("f->strs: %p\n", (f->strs));
	if (&(f->map->vars))
		free (&(f->map->vars));
/* 	if (&(f->map->data))
		free (&(f->map->data)); */
	

	free(f);
}
