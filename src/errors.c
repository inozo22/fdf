/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:36:39 by nimai             #+#    #+#             */
/*   Updated: 2023/04/25 12:45:53 by nimai            ###   ########.fr       */
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
		ft_putstr_fd("Map format error\n", STDERR);
		return (1);
	}
	if (type == 3)
	{
		ft_putstr_fd("Failed open file\n", STDERR);
		return (1);
	}
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

int	f_error(int type, t_f *f)
{
	if (type == 1)
	{
		ft_putstr_fd("Map format error\n", STDERR);
		all_free(f);
		return (1);
	}
	if (type == 2)
	{
		ft_putstr_fd("Map size error\n", STDERR);
		all_free(f);
		return (1);
	}
	if (type == 4)
	{
		ft_putstr_fd("the number is out of int\n", STDERR);
		all_free(f);
		return (1);
	}
	if (type == 5)
	{
		all_free(f);
		return (1);
	}
	return (0);
}
