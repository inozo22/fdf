/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:54:56 by nimai             #+#    #+#             */
/*   Updated: 2023/03/21 16:32:01 by nimai            ###   ########.fr       */
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
# include "./lib/mlx_linux/mlx.h"

//# include "./lib/minilibx_macos/mlx.h"

# define STDERR 2
# define ARGLIMIT 1024
# define WIN_WIDTH 2560
# define WIN_HEIGHT 1390
# define INTMAX 2147483647
# define INTMIN -2147483648

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
	long	value;
	char	*colour;
	long	x;
	long	y;
	long	z;
	long	x_mod;
	long	y_mod;
}	t_nmbs;

typedef struct s_line
{
	void			*content;
	struct s_line	*next;
	long			id_row[1024];
	long			id_column[1024];
}	t_line;

typedef struct s_fdf
{
	void			*content;
	struct s_line	*row;//kore de ii ki ga suru no se // kesu kamo
//	struct s_line	*column[ARGLIMIT];
    long			row_len;//length of the first row
//	long			clm_len;
	t_nmbs			n[ARGLIMIT][ARGLIMIT];
	long			column;
	char			**strs;
	long			is_first;//check norm
	long			height;
	long			width;
	long			w_cell;
}	t_fdf;

typedef struct s_map
{
	t_vars	vars;
	t_data	data;
}	t_map;

void	fdf(int fd);
int		main(int ac, char **av);
//int main(void);
int		hollow_error(int type);
int		fdf_error(int type, t_fdf *fdf);
void	all_free(t_fdf *fdf);
char	**strs_clear(char **tab, long i);
t_fdf	*init_fdf(int fd, t_fdf *fdf);
//void	open_window(t_fdf *fdf, t_map *map);
void	draw_map(t_map *map, t_fdf *fdf);
void	put_line_right(t_map *map, t_fdf *fdf, long y, long x);
void	hold_window(t_fdf *fdf, t_map *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	three_dimension(t_fdf *fdf, t_map *map);
void	get_slope(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2);
void	negative_high(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2);
void	negative_low(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2);
void	positive_high(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2);
void	positive_low(t_fdf *fdf, t_map *map, t_nmbs nbr1, t_nmbs nbr2);
void	convert_points_2d(t_fdf *fdf, t_data *data);
///
void	get_scale(t_map *map);
void	adjust_screen(t_fdf *fdf, t_map *map);
void	get_mid_x(t_fdf *fdf, t_map *map);
void	get_mid_y(t_fdf *fdf, t_map *map);


#endif
