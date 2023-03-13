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


// I have tried to work with lines, but maybe it's over-kill




/* t_line	*add_column(t_line *row, t_fdf *fdf, char *str)
{
	t_line	*new;

	dummy = (t_line *)malloc(sizeof(t_line));
	if (!dummy)
		exit(hollow_error(1));
	dummy->
} */

/* t_line	*get_dummy(void)
{
	t_line	*dummy;

	dummy = (t_line *)malloc(sizeof(t_line));
	if (!dummy)
		exit(hollow_error(1));
	dummy->
} */

int	count_word(char *str, t_fdf *fdf)
{
	int	ret;
	int	i;

	i = -1;
	ret = 0;
	if (!str)
		exit (hollow_error(3));
	while (str[++i] == 32)
		;
	while (str[i])
	{
		while (str[i] == 32)
			i++;
		if (str[i] < '0' || str[i] > '9')
			exit (hollow_error(2));
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		ret++;
		i++;
	}
	if (fdf->is_first)// if this is the first row, record the number and then compare later
	{
		fdf->first_row = ret;
		fdf->is_first = 0;
	}
	return (ret);
}

t_line	*get_first_row(char *str, t_line *row, t_fdf *fdf)
{
	char	**strs;
	int		len;
	int		i;

	fdf->is_first = 1;
	len = count_word(str, fdf);
/* 	ret = (t_line *)malloc(sizeof(t_line) * (len + 1));
	if (!ret)
		exit (hollow_error(1));//gigi ari, it's not necessary to release fdf memory? */
	strs = ft_split(str, 32);//separation is only spaces? but also tablation?
	i = -1;
	while (++i < len)
	{
		add_column(row, fdf, strs[i]);//2023/03/12 kokomade 
		
	}
	
}

t_line	*init_row(int fd, t_fdf *fdf)
{
	t_line	*row;
	char	*str;

//	ret = get_dummy();
	str = get_next_line(fd);
	row = get_first_row(str, ret, fdf);
/* 	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free (str);
		str = get_next_line(fd);
	} */
	return (row);
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

//for test
int	main(int ac, char **av)
{
	t_fdf	*test;
	int		i;
	char *str;

	if (ac = 2)
	{
		str = av[1];
		printf("%s\n", str);
		i = count_word(str, 1, test);
		printf("the word's number of the string is %d\n", i);
	}
	return (0);
}
