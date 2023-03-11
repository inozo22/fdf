/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:30:54 by nimai             #+#    #+#             */
/*   Updated: 2023/03/11 16:40:17 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	char	*str;
	int		fd;

	if (ac != 2)
	{
		ft_putstr_fd("Usage : ./fdf <filename> [ case_size z_size ]", 1);
		return (fdf_error(1));
	}

	return (0);
}
