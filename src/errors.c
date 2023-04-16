/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:36:39 by nimai             #+#    #+#             */
/*   Updated: 2023/04/11 18:24:35 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	hollow_error(int type)
{
	if (type == 1)
	{
		ft_putstr_fd("error without memory\n", STDERR);
		return (1);
	}
	if (type == 2)
	{
		ft_putstr_fd("map format error\n", STDERR);
		return (1);
	}
//230416 is commented
/* 	if (type == 3)
	{
		ft_putstr_fd("no argment\n", STDERR);
		return (1);
	} */
	if (type == 4)
	{
		ft_putstr_fd("fail memory allocate\n", STDERR);
		return (1);
	}
	if (type == 5)
	{
		return (1);
	}
	return (0);
}

int	fdf_error(int type, t_fdf *fdf)
{
	if (type == 1)
	{
		ft_putstr_fd("Map format error\n", STDERR);
		fdf_free(fdf);
		return (1);
	}
	if (type == 2)
	{
		ft_putstr_fd("Map size error\n", STDERR);
		fdf_free(fdf);
		return (1);
	}
//230416 is deleted
/* 	if (type == 3)
	{
		ft_putstr_fd("the map is not enclosed by 0\n", STDERR);
		fdf_free(fdf);
		return (1);
	} */
	if (type == 4)
	{
		ft_putstr_fd("the number is out of int\n", STDERR);
		fdf_free(fdf);
		return (1);
	}
	return (0);
}
