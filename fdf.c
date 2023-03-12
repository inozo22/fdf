/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:52:18 by nimai             #+#    #+#             */
/*   Updated: 2023/03/12 11:46:05 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* t_line	*get_dummy(void)
{
	t_line	*dummy;

	dummy = (t_line *)malloc(sizeof(t_line));
	if (!dummy)
		exit(hollow_error(1));
	dummy->
} */

int	count_word(char *str, int is_first, t_fdf *fdf)
{
	int	ret;
	int	i;

	i = -1;
	ret = 0;
	while (str[++i] == 32)
		;
	while (str[++i])
	{
		while (str[i] == 32)
			i++;
		if (str[i] < '0' || str[i] > '9')
			exit (hollow_error(1));
		ret++;
	}
	if (is_first)// if this is the first row, record the number and then compare later
		fdf->first_row = ret;
	return (ret);
}

t_line	*get_first_row(char *str, t_line *ret, t_fdf *fdf)
{
	int	len;
	int	i;
	int	is_first;

	is_first = 1;
	len = count_word(str, is_first, fdf);
	ret = (t_line *)malloc(sizeof(t_line) * (len + 1));
	if (!ret)
		exit (hollow_error(1));//gigi ari
	i = -1;
	while (++i < len)
	{
		
	}
	
}

t_line	*init_row(int fd, t_fdf *fdf)
{
	t_line	*ret;
	char	*str;

//	ret = get_dummy();
	str = get_next_line(fd);
	ret = get_first_row(str, ret, fdf);
/* 	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free (str);
		str = get_next_line(fd);
	} */
	return (ret);
}

t_fdf	*init_fdf(int fd, t_fdf *fdf)
{
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		exit (hollow_error(1));//error without memory
	fdf->row = init_row(fd, fdf);

//	fdf->column = init_column(fd, fdf->column);	
	return (fdf);
}

void	fdf(int fd)
{
	t_fdf	*fdf;


	

	fdf = init_fdf(fd, fdf);
//	fdf->row = init_row(fdf);

}
