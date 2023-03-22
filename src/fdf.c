/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:52:18 by nimai             #+#    #+#             */
/*   Updated: 2023/03/22 12:15:19 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//20230319: get the width and height for both window and image
//and then calculate the length of each cell width
void	get_size(t_fdf *fdf)
{
	if ((fdf->row_len * 50) > 1920)
		fdf->width = 1920;
	else
		fdf->width = fdf->row_len * 50;
	if ((fdf->column * 50) > 1080)
		fdf->height = 1080;
	else
		fdf->height = fdf->column * 50;
	fdf->w_cell = fdf->width * 0.75 / fdf->row_len;
}

int	get_colour(char *str, int i, int row, t_fdf *fdf)
{
	char	tmp[20];
	int		j;

	j = 0;

	++i;
	if (str[i] != '0' || (str[i + 1]  != 'x'))
		exit (fdf_error(5, fdf));//koreha hexa janai error
	i = i + 2;
	while (str[i] && str[i] != 32)
	{
		tmp[j] = str[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	fdf->n[fdf->column][row].colour = tmp;
	return (i);
}

bool	check_amount(t_fdf *fdf, int ret)
{
	if (fdf->is_first)
	{
		fdf->row_len = ret;
		fdf->is_first = 0;
	}
	else// I may have to omid this
	{
		if (ret != fdf->row_len)
			return (false);
	}
	return (true);
}

int	count_word(char *str, t_fdf *fdf)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	if (!str)
		exit (hollow_error(3));
	while (str[i] && (str[i] == 32 || str[i] == 't'))
		i++;
	while (str[i] && str[i] != 10)
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] < '0' || str[i] > '9')
			exit (hollow_error(2));
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		ret++;
		if (str[i] == ',')
			i = get_colour(str, i, ret - 1, fdf);
		while (str[i] == 32 || str[i] == 't')
			i++;
	}
	if (!check_amount(fdf, ret))
		exit(fdf_error(2, fdf));
	return (ret);
}


void	fill_n(t_fdf *fdf, int size)
{
	int	i;

	i = 0;
	while (fdf->strs[i] && i < size)
	{
		fdf->n[fdf->column][i].z = ft_atoi(fdf->strs[i]);
		fdf->n[fdf->column][i].x = i;
		fdf->n[fdf->column][i].y = fdf->column;
		i++;
	}
//	printf("I'm here: %d\n", __LINE__);
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
	int		size;

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
	close (fd);
	free (str);
}

//the fd already has been opened
t_fdf	*init_fdf(int fd, t_fdf *fdf)
{
	int	i;
	int	j;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		exit (hollow_error(1));//error without memory
	fill_data(fd, fdf);

//printer
	j = -1;
	while (++j < fdf->column)
	{
		i = -1;
		while (++i < fdf->row_len)
		{
			printf("%d ", fdf->n[j][i].z);
		}
		printf("\n");
	}
	printf("fdf->column: %d\nfdf->row_len: %d\n", fdf->column, fdf->row_len);
//printer
	return (fdf);
}

t_map	*init_map(t_map *map, t_fdf *fdf)
{
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit (hollow_error(1));//error without memory
// koko made
	map->vars.mlx = mlx_init();
	if (map->vars.mlx == NULL)
	{
		perror("Unable to create mlx pointer\n");
		exit(2);//memory release?
	}
	map->vars.win = mlx_new_window(map->vars.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (map->vars.win == NULL)
	{
		perror("Unable to create window pointer\n");
		exit(2);//memory release?
	}
	map->data.img = mlx_new_image(map->vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	map->data.addr = mlx_get_data_addr(map->data.img, &map->data.bits_per_pixel, &map->data.line_length, &map->data.endian);
	return (map);
}

void	fdf(int fd)
{
	t_fdf	*fdf;
	t_map	*map;

	fdf = NULL;
	fdf = init_fdf(fd, fdf);
	map = init_map(map, fdf);
//	open_window(fdf, map);
	convert_points_2d(fdf, &map->data);
//	printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
	get_mid_x(fdf, map);
	get_mid_y(fdf, map);
	get_scale(map);
//	adjust_screen(fdf, map);
	printf("where am I: %d\nfile: %s\n", __LINE__, __FILE__);
	hold_window(fdf, map);
	printf("map made\n");
	all_free (fdf);
}
