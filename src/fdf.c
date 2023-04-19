/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:52:18 by nimai             #+#    #+#             */
/*   Updated: 2023/04/19 17:29:03 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fill_n(t_f *f, int size)
{
	int	i;

	i = 0;
	while (f->strs[i] && i < size)
	{
		f->n[f->column][i].z = ft_atoi(f->strs[i]);
		f->n[f->column][i].x = i;
		f->n[f->column][i].y = f->column;
		i++;
	}
	while (i < ARGLIMIT)
	{
		f->n[f->column][i].z = 0;
		f->n[f->column][i].x = i;
		f->n[f->column][i].y = f->column;
		i++;
	}
}

void	fill_data(int fd, t_f *f)
{
	char	*str;
	int		size;

	f->is_first = 1;
	str = get_next_line(fd);
	f->column = 0;
	while (str)
	{
		size = count_word(str, f);
		f->strs = ft_split(str, 32);
		fill_n(f, size);
		strs_clear(f->strs, size);
		free (str);
		str = get_next_line(fd);
		f->column++;
	}
	close (fd);
	free (str);
}

t_f	*init_f(int fd, t_f *f)
{
	int	i;
	int	j;

	f = (t_f *)malloc(sizeof(t_f));
	if (!f)
		exit (hollow_error(4));
	j = -1;
	while (++j < ARGLIMIT)
	{
		i = -1;
		while (++i < ARGLIMIT)
		{
			f->n[j][i].colour = 0xffffff;
		}
	}
	fill_data(fd, f);
	return (f);
}

t_map	*init_map(t_f *f)
{
	f->map = (t_map *)malloc(sizeof(t_map));
	if (!f->map)
	{
		all_free(f);
		exit (hollow_error(4));
	}
	f->map->vars.mlx = mlx_init();
	f->map->mag = 0.8;
	if (f->map->vars.mlx == NULL)
	{
		perror("Unable to create mlx pointer\n");
		exit(f_error(5, f));
	}
	f->map->vars.win = mlx_new_window(f->map->vars.mlx, \
	WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (f->map->vars.win == NULL)
	{
		perror("Unable to create window pointer\n");
		exit(f_error(5, f));
	}
	f->map->data.img = mlx_new_image(f->map->vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	f->map->data.addr = mlx_get_data_addr(f->map->data.img, \
	&f->map->data.bits_per_pixel, &f->map->data.line_length, \
	&f->map->data.endian);
	return (f->map);
}

void	fdf(int fd)
{
	t_f	*f;

	f = NULL;
	f = init_f(fd, f);
	f->map = init_map(f);
	convert_points_2d(f);
	get_mid_x(f);
	get_mid_y(f);
	get_scale(f);
	hold_window(f);
	all_free(f);
}
