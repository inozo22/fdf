/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:54:56 by nimai             #+#    #+#             */
/*   Updated: 2023/04/17 15:21:34 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./lib/libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <errno.h>
//# include "./lib/mlx_linux/mlx.h"
# include "./lib/minilibx_macos/mlx.h"

# define STDERR 2
# define ARGLIMIT 1024
# define WIN_WIDTH 2560
# define WIN_HEIGHT 1390

//key control
# define KEY_ESC 53
# define KEY_Q 12

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			center_x;
	int			center_y;
	int			width;
	int			height;
	double		scale;
}	t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
}	t_vars;

typedef struct s_nmbs
{
	int		len;
	int		colour;
	int		x;
	int		y;
	int		z;
	int		x_mod;
	int		y_mod;
	int		grd[ARGLIMIT];
}	t_nmbs;

typedef struct s_fdf
{
	int				row_len;
	t_nmbs			n[ARGLIMIT][ARGLIMIT];
	int				column;
	char			**strs;
	int				is_first;
	int				height;
	int				width;
	int				w_cell;
	int				pwd_j;
	int				pwd_i;
	int				dd;
	int				dx;
	int				dy;
}	t_fdf;

typedef struct s_map
{
	t_vars	vars;
	t_data	data;
	float	mag;
}	t_map;

void		fdf(int fd);
int			main(int ac, char **av);
int			hollow_error(int type);
int			fdf_error(int type, t_fdf *fdf);
void		fdf_free(t_fdf *fdf);
void		all_free(t_fdf *fdf, t_map *map);
char		**strs_clear(char **tab, int i);
t_fdf		*init_fdf(int fd, t_fdf *fdf);
void		draw_ver(t_map *map, t_fdf *fdf);
void		put_line_right(t_map *map, t_fdf *fdf, int y, int x);
void		hold_window(t_fdf *fdf, t_map *map);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		three_dimension(t_fdf *fdf, t_map *map);
void		get_slope(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2);
void		negative_high(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2);
void		negative_low(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2);
void		positive_high(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2);
void		positive_low(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2);
void		convert_points_2d(t_fdf *fdf, t_data *data);
//
void		get_scale(t_map *map);
void		adjust_screen(t_fdf *fdf, t_map *map);
void		get_mid_x(t_fdf *fdf, t_map *map);
void		get_mid_y(t_fdf *fdf, t_map *map);

int			count_word(char *str, t_fdf *fdf);
bool		check_amount(t_fdf *fdf, int ret);
int			get_colour(char *str, int i, int row, t_fdf *fdf);
int			hexatoi(char	*str);
//
void		u_gradate_colour(t_fdf *fdf, int j, int i, t_map *map);
void		r_gradate_colour(t_fdf *fdf, int j, int i, t_map *map);
void		ur_gradate_colour(t_fdf *fdf, int j, int i, t_map *map);
void		g_negative_high(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2);
void		g_negative_low(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2);
void		g_positive_high(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2);
void		g_positive_low(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2);
void		g_get_slope(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2);
static void	g_swap_nbr(t_fdf *fdf, t_map *map, t_nmbs *nbr1, t_nmbs *nbr2);
void		gradiente(int start, int end, t_fdf *fdf);

int			terminate_fdf(void	*param);
void		control_keys(int key, t_map *map);
int			key_press(int key, void *param);

#endif
