/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:52:18 by nimai             #+#    #+#             */
/*   Updated: 2023/03/14 17:52:26 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long	get_colour(char *str, long i, long row, t_fdf *fdf)
{
	char	tmp[20];
	long	j;

	j = 0;
	if (!(str[++i] == '0' && (str[i + 1]  == 'x'|| str[i + 1] == 'X')))
		exit (fdf_error(5, fdf));//koreha hexa janai error
	i++;
	while (str[++i] != 32)
	{
		tmp[j] = str[i];
		j++;
	}
	fdf->n[fdf->column][row].colour = tmp;
//	printf("print colour: %s\nprint counter i:%ld\n", fdf->n[fdf->column][row].colour, i);
	return (i);
}

void	draw_map(t_fdf *fdf)//check all rows
{
	long	i;
	long	j;

	i = -1;
	j = -1;
	while (++j < fdf->column)
	{
		while (++i < fdf->row_len)
		{
			if (fdf->n[j][i].value < INTMIN || fdf->n[j][i].value > INTMAX)//check the first row->OK
				exit (fdf_error(4, fdf));
			if (i != fdf->row_len - 1)
			{
				if (fdf->n[j][i].value == fdf->n[j][i + 1].value)//order to draw the line
					printf("put a straight line to the right\n");
				else
					printf("calculate the slope\n");
			}
			if (i != fdf->column - 1)
			{
				if (fdf->n[j][i].value == fdf->n[j + 1][i].value)//order to draw the line
					printf("put a straight line to the bottom\n");
				else
					printf("calculate the slope\n");
			}
		}
	}
}

/* bool	is_enclosed(t_fdf *fdf)
{
	long	i;

	i = -1;
	printf("row_len: %ld\ncolumn: %ld\n", fdf->row_len, fdf->column);
	while (++i < fdf->row_len)
	{
		if (fdf->n[0][i].value != 0)//check the first row->OK
			return (false);
		if (fdf->n[fdf->column - 1][i].value != 0)//check the last row->OK
			return (false);
		printf("first row[%ld]: %ld\nlast row[%ld]: %ld\n",i ,fdf->n[0][i].value, i, fdf->n[fdf->column][i].value);
	}
	i = -1;
	while (++i < fdf->column)
	{
		if (fdf->n[i][0].value != 0)//check the first column->OK
			return (false);
		if (fdf->n[i][fdf->row_len - 1].value != 0)//check the last column->OK
			return (false);
		printf("first clm[%ld]: %ld\nlast clm[%ld]: %ld\n",i, fdf->n[i][0].value, i, fdf->n[i][fdf->row_len].value);
	}
	return (true);
} */

bool check_amount(t_fdf *fdf, long ret)
{
	if (fdf->is_first)// if this is the first row, record the number and then compare later
	{
		fdf->row_len = ret;
		fdf->is_first = 0;
	}
	else
	{
		if (ret != fdf->row_len)
			return (false);
	}
	return (true);
}

long	count_word(char *str, t_fdf *fdf)
{
	long	ret;
	long	i;

	i = -1;
	ret = 0;
	if (!str)
		exit (hollow_error(3));
	while (str[++i] == 32)
		;
	while (str[i] != '\0' && str[i] != 10)
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] < '0' || str[i] > '9')
			exit (hollow_error(2));
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == ',')
			i = get_colour(str, i, ret, fdf);
		ret++;
		i++;
		while (str[i] == 32)
			i++;
	}
	printf("count_number ret: %ld\n", ret);
	if (!check_amount(fdf, ret))
		exit(fdf_error(2, fdf));
	return (ret);
}


void	fill_n(t_fdf *fdf, long size)
{
	long	i;

	i = -1;
	while (++i < size)
	{
		fdf->n[fdf->column][i].value = ft_atoi(fdf->strs[i]);
		fdf->n[fdf->column][i].id_x = i;
		fdf->n[fdf->column][i].id_y = fdf->column;
	}
	while (i < ARGLIMIT)//check if it's ok leave this as empty
	{
		fdf->n[fdf->column][i].value = 0;//you kentou
		fdf->n[fdf->column][i].id_x = i;
		fdf->n[fdf->column][i].id_y = fdf->column;
		i++;
	}
}

void	fill_data(int fd, t_fdf *fdf)
{
	char	*str;
	long	size;
	
	fdf->is_first = 1;
	str = get_next_line(fd);
 	fdf->column = 0;
	while (str)
	{
		size = count_word(str, fdf);
		fdf->strs = ft_split(str, 32);
		fill_n(fdf, size);
		strs_clear(fdf->strs, size);
		free (str);
		str = get_next_line(fd);
		fdf->column++;
	}
//	strs_clear(fdf->strs, size);
	free (str);
}

//the fd already has been opened
t_fdf	*init_fdf(int fd, t_fdf *fdf)
{
	long	i;
	long	j;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		exit (hollow_error(1));//error without memory
	fill_data(fd, fdf);
// koko made


	printf("fdf->column: %ld\n", fdf->column);	
	i = 0;
	j = -1;
	while (++j < fdf->column)
	{
		while (i < fdf->row_len)
		{
			printf("%ld ", fdf->n[j][i].value);
			i++;
		}
		printf("\n");
		i = 0;
	}


//	fdf->column = init_column(fd, fdf->column);	
	return (fdf);
}



void	fdf(int fd)
{
	t_fdf	*fdf;

	fdf = NULL;
	fdf = init_fdf(fd, fdf);
/* 	if (!(is_enclosed(fdf)))
		exit (fdf_error(3, fdf)); */
	printf("calculate the map size according to the fdf->row_len and fdf->column\n");
	printf("start the map\n");
	draw_map(fdf);
	printf("is enclosed\n");
	all_free (fdf);
}

//for test
/* int	main(int ac, char **av)
{
	char	*str;
	int		fd;

	if (ac != 2)
	{
		ft_putstr_fd("Usage : ./fdf <filename> [ case_size z_size ]", 1);
		exit (hollow_error(1));
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		exit (hollow_error(1));
	fdf(fd);

	close(fd);
	return (0);
} */

