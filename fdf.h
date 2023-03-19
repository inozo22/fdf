/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:54:56 by nimai             #+#    #+#             */
/*   Updated: 2023/03/18 12:17:02 by nimai            ###   ########.fr       */
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
# include "./lib/mlx_linux/mlx.h"

//# include "./lib/minilibx_macos/mlx.h"

# define STDERR 2
# define ARGLIMIT 1024
# define INTMAX 2147483647
# define INTMIN -2147483648

//key control
# define KEY_ESC 53

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	/* data */
//	struct s_data	*data;
}	t_vars;

typedef struct s_nmbs
{
	long	value;
	char	*colour;
	long	id_x;
	long	id_y;
}	t_nmbs;

typedef struct s_line
{
	void			*content;
	struct s_line	*next;
//	struct s_line	*prev;
	long				id_row[1024];
	long				id_column[1024];
}	t_line;

typedef struct s_fdf
{
	void			*content;
	struct s_line	*row;//kore de ii ki ga suru no se
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
	/* data */
}	t_map;


void	fdf(int fd);
int		main(int ac, char **av);
//int main(void);
int		hollow_error(int type);
int		fdf_error(int type, t_fdf *fdf);
void	all_free(t_fdf *fdf);
char	**strs_clear(char **tab, long i);
t_fdf	*init_fdf(int fd, t_fdf *fdf);
void	open_window(t_fdf *fdf, t_map *map);
void	draw_map(t_map *map, t_fdf *fdf);
void	put_line_right(t_map *map, t_fdf *fdf, long y, long x);

#endif
