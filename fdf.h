/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:54:56 by nimai             #+#    #+#             */
/*   Updated: 2023/03/12 11:46:23 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./lib/libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "./lib/mlx_linux/mlx.h"
# include "./lib/minilibx_macos/mlx.h"

# define STDERR 2
# define ARGLIMIT 1024


typedef struct s_nmbs
{
	long	value;
	long	id_x;
	long	id_y;
}	t_nmbs;

typedef struct s_line
{
	void			*content;
	struct s_line	*next;
//	struct s_line	*prev;
	int				id_row[1024];
	int				id_column[1024];
}	t_line;

typedef struct s_fdf
{
	void			*content;
	struct s_line	*row;//kore de ii ki ga suru no se
//	struct s_line	*column[ARGLIMIT];
    int             row_len;//length of the first row
	int				clm_len;
	t_nmbs			n[ARGLIMIT];

//	int				is_first;//check norm
}	t_fdf;

int	main(int ac, char **av);
//int main(void);
int	hollow_error(int type);
int	fdf_error(int type, t_fdf *fdf);

#endif
