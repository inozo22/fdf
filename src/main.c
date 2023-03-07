/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:50:40 by nimai             #+#    #+#             */
/*   Updated: 2023/03/07 12:25:33 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(void)
{
	char	*str;
	int		fd;

	str = " ";
	fd = open("test.txt", O_RDONLY);
	while (str)
	{
		str = get_next_line(fd);
		printf("> %s", str);
		free(str);

	}
	close(fd);
	return (0);
}
