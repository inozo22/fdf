/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:30:54 by nimai             #+#    #+#             */
/*   Updated: 2023/04/17 15:22:55 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		ft_putstr_fd("Usage : ./fdf <filename>", 1);
		exit (hollow_error(5));
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		exit (hollow_error(3));
	fdf(fd);
	return (0);
}
