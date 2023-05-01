/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:30:54 by nimai             #+#    #+#             */
/*   Updated: 2023/05/01 13:15:07 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_format(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '.' && str[i + 1] == 'f' && str[i + 2] == 'd' && \
		str[i + 3] == 'f' && str[i + 4] == '\0')
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
	{
		ft_putstr_fd("Usage : ./fdf <filename>", 1);
		exit (hollow_error(5));
	}
	if (check_format(av[1]) == 0)
	{
		ft_putstr_fd("You can only use file type: .fdf", 1);
		exit (hollow_error(5));
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 1)
	{
		exit (hollow_error(3));
	}
	fdf(fd);
	return (0);
}
