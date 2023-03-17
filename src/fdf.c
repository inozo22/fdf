/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:52:18 by nimai             #+#    #+#             */
/*   Updated: 2023/03/17 14:50:37 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

long	get_colour(char *str, long i, long row, t_fdf *fdf)
{
	char	tmp[20];
	long	j;

	j = 0;

	++i;
	if (!(str[i] == '0' && (str[i + 1]  == 'x'|| str[i + 1] == 'X')))
		exit (fdf_error(5, fdf));//koreha hexa janai error
	i++;
	while (str[++i] != 32 && row < fdf->row_len)
	{
		tmp[j] = str[i];
		j++;
	}
	tmp[j] = '\0';
	fdf->n[fdf->column][row].colour = tmp;
//	printf("I'm here: %d\ncolour: %s\nfdf->column: %ld\nrow: %ld\n", __LINE__, fdf->n[fdf->column][row].colour, fdf->column, row);
	return (i);
}

bool	check_amount(t_fdf *fdf, long ret)
{
	if (fdf->is_first)
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
	printf("I'm here: %d\n", __LINE__);
	while (str[++i] == 32|| str[i] == 't')
		;
	printf("I'm here: %d\n", __LINE__);
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
		while (str[i] == 32 || str[i] == 't')
			i++;
	}
	printf("I need retttttt =%ld\nstr= %s\nfdf->column= %ld\n", ret, str, fdf->column);
	if (!check_amount(fdf, ret))
		exit(fdf_error(2, fdf));
	printf("I'm here in c word: %d\nret: %ld\n", __LINE__, ret);
	return (ret);
}


void	fill_n(t_fdf *fdf, long size)
{
	long	i;

	i = 0;
//	printf("I'm here: %d\n", __LINE__);
	printf("yahoooo size: %ld\n", size);
	while (fdf->strs[i] && i < size)
	{
		fdf->n[fdf->column][i].value = ft_atoi(fdf->strs[i]);
		fdf->n[fdf->column][i].id_x = i;
		fdf->n[fdf->column][i].id_y = fdf->column;
		i++;
	//	printf("I'm here: %d\ni	:%ld\ncolumn	:%ld\n", __LINE__, i, fdf->column);
	}
	printf("I'm here: %d\n", __LINE__);
/* 	while (i < ARGLIMIT)//check if it's ok leave this as empty
	{
		fdf->n[fdf->column][i].value = 0;//you kentou
		fdf->n[fdf->column][i].id_x = i;
		fdf->n[fdf->column][i].id_y = fdf->column;
		printf("I'm here: %d\ni	:%ld\ncolumn	:%ld\n", __LINE__, i, fdf->column);
		i++;
	} */
}

void	fill_data(int fd, t_fdf *fdf)
{
	char	*str;
	long	size;

	fdf->is_first = 1;
	str = get_next_line(fd);
	fdf->column = 0;
//	printf("I'm here: %d\n", __LINE__);
	while (str)
	{
		printf("I'm here: %d\n", __LINE__);
	//	printf("str: %s\n", str);
		size = count_word(str, fdf);
		printf("I'm here after count: %d\nsize: %ld\n", __LINE__, size);
		fdf->strs = ft_split(str, 32);
		printf("I'm here: %d\nsize: %ld\n", __LINE__, size);
		fill_n(fdf, size);
		printf("I'm here: %d\nsize: %ld\n", __LINE__, size);
		printf("pointer strs: %p\npointer str: %p\n", fdf->strs, str);
		strs_clear(fdf->strs, size);
		printf("I'm here: %d\n", __LINE__);
		free (str);
		printf("I'm here: %d\n", __LINE__);
		str = get_next_line(fd);
		fdf->column++;
		size = 0;
	}
//	strs_clear(fdf->strs, size);//kore ireru to double free
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
	return (fdf);
}

t_map	*init_map(t_map *map, t_fdf *fdf)
{
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit (hollow_error(1));//error without memory
	open_window(fdf, map);
// koko made

	return (map);
}

void	fdf(int fd)
{
	t_fdf	*fdf;
	t_map	*map;

	fdf = NULL;
	fdf = init_fdf(fd, fdf);
	map = init_map(map, fdf);

//	draw_map(fdf);
	printf("map made\n");
	all_free (fdf);
}
