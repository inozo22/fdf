/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:52:18 by nimai             #+#    #+#             */
/*   Updated: 2023/04/07 14:37:59 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	hexatoi(char	*str)
{
	int		ret;
	int		i;
	int		len;
	char	*base_l;
	char	*base_u;

	base_l = "0123456789abcdef";
	base_u = "0123456789ABCDEF";

	ret = 0;
	len = ft_strlen(str) - 1;
	while (*str)
	{
		i = -1;
		while (++i < 16)
		{
			if (*str == base_l[i] || *str == base_u[i])
			{
				ret = ret + i * pow(16, len);
				len--;
			}
		}
		str++;
	}
	return (ret);
}

int	get_colour(char *str, int i, int row, t_fdf *fdf)
{
	char	tmp[20];
	int		j;

	j = 0;

	++i;
	if (str[i] != '0' || (str[i + 1] != 'x'))
		exit (fdf_error(5, fdf));
	i = i + 2;
	while (str[i] && str[i] != 32)
	{
		tmp[j] = str[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	fdf->n[fdf->column][row].colour = hexatoi(tmp);
	return (i);
}

bool	check_amount(t_fdf *fdf, int ret)
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

int	count_word(char *str, t_fdf *fdf)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
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
		if (!fdf->n[fdf->column][i].colour)
			fdf->n[fdf->column][i].colour = 0xffffff;
		i++;
	}
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
	return (fdf);
}

t_map	*init_map(t_map *map, t_fdf *fdf)
{
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit (hollow_error(1));//error without memory
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
	map->data.addr = mlx_get_data_addr(map->data.img, \
	&map->data.bits_per_pixel, &map->data.line_length, &map->data.endian);
	return (map);
}

void	fdf(int fd)
{
	t_fdf	*fdf;
	t_map	*map;

	fdf = NULL;
	fdf = init_fdf(fd, fdf);
	map = init_map(map, fdf);
	convert_points_2d(fdf, &map->data);
	get_mid_x(fdf, map);
	get_mid_y(fdf, map);
	get_scale(map);
	hold_window(fdf, map);
	all_free (fdf);
}
