/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:52:18 by nimai             #+#    #+#             */
/*   Updated: 2023/03/13 15:22:56 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	while (str[i])
	{
		while (str[i] == 32)
			i++;
		if (str[i] == '-' || str[i] == '+')
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
		fdf->row_len = ret;
		fdf->is_first = 0;
	}
	else
	{
		if (ret != fdf->row_len)
			exit(fdf_error(2, fdf));
	}
	return (ret);
}

	
void	fill_data(int fd, t_fdf *fdf)
{
	char	*str;
	long	size;
	long	i;
	
	fdf->is_first = 1;
	str = get_next_line(fd);
	fdf->column = 0;

	while (str)
	{
		size = count_word(str, fdf);
		fdf->strs = ft_split(str, 32);
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
		strs_clear(fdf->strs, size);
		free (str);
		str = get_next_line(fd);
		fdf->column++;
	}	
}

/* t_line	*get_first_row(char *str, t_line *row, t_fdf *fdf)
{
	char	**strs;
	int		len;
	int		i;

	fdf->is_first = 1;
	len = count_word(str, fdf);
 	ret = (t_line *)malloc(sizeof(t_line) * (len + 1));
	if (!ret)
		exit (hollow_error(1));//gigi ari, it's not necessary to release fdf memory? 
	strs = ft_split(str, 32);//separation is only spaces? but also tablation?
	i = -1;
	while (++i < len)
	{
		add_column(row, fdf, strs[i]);//2023/03/12 kokomade 
		
	}
	
} */

/* t_line	*init_row(int fd, t_fdf *fdf)
{
	t_line	*row;


//	ret = get_dummy();
	str = get_next_line(fd);
	row = get_first_row(str, ret, fdf);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free (str);
		str = get_next_line(fd);
	}
	return (row);
} */

//the fd already has been opened
t_fdf	*init_fdf(int fd, t_fdf *fdf)
{
//	char	*str;
//	char	**strs;
//	long	size;
	long	i;
	long	j;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		exit (hollow_error(1));//error without memory
//	fdf->row = init_row(fd, fdf);
	fill_data(fd, fdf);
/* 	fdf->is_first = 1;
	str = get_next_line(fd);
	fdf->column = 0;

	while (str)
	{
		size = count_word(str, fdf);
		strs = ft_split(str, 32);
		i = -1;
		while (++i < size)
		{
			fdf->n[fdf->column][i].value = ft_atoi(strs[i]);
//			printf("%ld\n", fdf->n[fdf->column][i].value);
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
		free (str);
		str = get_next_line(fd);
		fdf->column++;
	} */
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


	

	fdf = init_fdf(fd, fdf);
//	fdf->row = init_row(fdf);
	all_free (fdf);
}

//for test
int	main(int ac, char **av)
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
}

