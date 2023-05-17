/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:54:56 by nimai             #+#    #+#             */
/*   Updated: 2023/05/17 12:47:06 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft/inc/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <errno.h>
# include "../lib/minilibx_macos/mlx.h"

# define STDERR 2
# define ARGLIMIT 1024
# define WIN_WIDTH 2560
# define WIN_HEIGHT 1390

//key control
# define KEY_ESC 53
# define KEY_Q 12

/**
* @brief gain data for the image
* @note it's included in t_map to free with main structure.
*/
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

/**
* @brief to open the map with mlx
* @note it's included in t_map to free with main structure.
*/
typedef struct s_vars
{
	void			*mlx;
	void			*win;
}	t_vars;

/**
* @brief map data control
* @note it's included in t_f.
*/
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

/**
* @brief binding all data to put image to the window
* @note it's included in t_f to free with main structure.
*/
typedef struct s_map
{
	t_vars	vars;
	t_data	data;
	float	mag;
}	t_map;

/**
* @brief main structure.
* @param pwd_j to pass where you are.
* @param pwd_i to pass where you are.
* @note it's necessary when terminate this program to free everything.
*/
typedef struct s_f
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
	t_map			*map;
	int				flag;
}	t_f;

int			main(int ac, char **av);

/**
* @brief main function, control initialization and move to hold_window
* @sa hold_window(t_f f)
*/
void		fdf(int fd);

/**
* @brief put error message
* @return 1 (type 1 - 5)
*/
int			hollow_error(int type);

/**
* @brief put error message and free f.
* @return 1 (type 1, 2, 4, 5)
*/
int			f_error(int type, t_f *f);

/**
* @brief free map->vars first, and then free f.
*/
void		all_free(t_f *f);

/**
* @brief free **tab with loop
* @return NULL
*/
char		**strs_clear(char **tab, int i);

/**
* @brief initialization of main structure
* @return f->map
* @note COULD BE BETTER
*/
t_f			*init_f(int fd, t_f *f);

/**
* @brief initialization of mlx map, also control map margin
* @return f->map
*/
t_map		*init_map(t_f *f);
void		draw_ver(t_f *f);
void		put_line_right(t_f *f, int y, int x);
void		hold_window(t_f *f);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

/**
* @brief passing params according to the position
* @note also record its position to calculate the gradation
*/
void		three_dimension(t_f *f);

/**
* @brief if the color is differ, send to gradation after get line data
*/
void		check_slope_colour(t_f *f, int j, int i);

/**
* @brief if the color is differ, send to gradation after get line data
*/
void		check_slope_colour_edge(t_f *f, int j, int i);
void		get_slope(t_f *f, t_nmbs nbr1, t_nmbs nbr2);
void		negative_high(t_f *f, t_nmbs nbr1, t_nmbs nbr2);
void		negative_low(t_f *f, t_nmbs nbr1, t_nmbs nbr2);
void		positive_high(t_f *f, t_nmbs nbr1, t_nmbs nbr2);
void		positive_low(t_f *f, t_nmbs nbr1, t_nmbs nbr2);
void		convert_points_2d(t_f *f);

void		get_scale(t_f *f);
void		adjust_screen(t_f *f);
void		get_mid_x(t_f *f);
void		get_mid_y(t_f *f);

/**
* @return  length of the str.
*/
int			count_word(char *str, t_f *f);

/**
* @return  false if ret != f->row_len.
*/
bool		check_amount(t_f *f, int ret);

/**
* @brief log the colour to f, and move to the next position.
* @return i, moved at the end of colour.
*/
int			get_colour(char *str, int i, int row, t_f *f);

/**
* @brief change char to int and calculate from hexadecimal to decimal.
* @return decimal number in int.
*/
int			hexatoi(char	*str);

void		u_gradate_colour(t_f *f, int j, int i);
void		r_gradate_colour(t_f *f, int j, int i);
void		ur_gradate_colour(t_f *f, int j, int i);
void		g_negative_high(t_f *f, t_nmbs nbr1, t_nmbs nbr2);
void		g_negative_low(t_f *f, t_nmbs nbr1, t_nmbs nbr2);
void		g_positive_high(t_f *f, t_nmbs nbr1, t_nmbs nbr2);
void		g_positive_low(t_f *f, t_nmbs nbr1, t_nmbs nbr2);
void		g_get_slope(t_f *f, t_nmbs nbr1, t_nmbs nbr2);

/**
* @brief  Calculate gradiente according to the length of the line
* @note  put each color to f->n[f->pwd_j][f->pwd_i].grd[c]
*/
void		gradiente(int start, int end, t_f *f);

/**
* @brief  Terminate fdf only here, except having error
* @note  when use system function, put here
*/
int			terminate_fdf(void	*param);
void		control_keys(int key, t_f *f);
int			key_press(int key, void *param);

void		g_negative_high_b(t_f *f, t_nmbs nbr1, t_nmbs nbr2);
void		g_negative_low_b(t_f *f, t_nmbs nbr1, t_nmbs nbr2);
void		g_positive_high_b(t_f *f, t_nmbs nbr1, t_nmbs nbr2);
void		g_positive_low_b(t_f *f, t_nmbs nbr1, t_nmbs nbr2);

#endif
