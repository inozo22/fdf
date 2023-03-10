/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:36:39 by nimai             #+#    #+#             */
/*   Updated: 2023/03/14 16:37:43 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	hollow_error(int type)
{
	if (type == 1)//error memory release unnecessary
	{
		ft_putstr_fd("error without memory\n", STDERR);
		return (1);
	}
	if (type == 2)//error memory release unnecessary
	{
		ft_putstr_fd("count number error\n", STDERR);
		return (1);
	}
	if (type == 3)//error memory release unnecessary
	{
		ft_putstr_fd("no argment\n", STDERR);
		return (1);
	}
	return (0);
}

int	fdf_error(int type, t_fdf *fdf)
{
	if (type == 1)
	{
		ft_putstr_fd("error with memory\n", STDERR);
		all_free(fdf);
		return (1);
	}
	if (type == 2)
	{
		ft_putstr_fd("map size error\n", STDERR);
		all_free(fdf);
		return (1);
	}
	if (type == 3)//error memory release necessary
	{
		ft_putstr_fd("the map is not enclosed by 0\n", STDERR);
		all_free(fdf);
		return (1);
	}
	if (type == 4)//error memory release necessary
	{
		ft_putstr_fd("the number is out of int\n", STDERR);
		all_free(fdf);
		return (1);
	}
	if (type == 5)//error memory release necessary
	{
		ft_putstr_fd("the colour code is not hexa\n", STDERR);
		all_free(fdf);
		return (1);
	}
	return (0);
}
