/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:54:56 by nimai             #+#    #+#             */
/*   Updated: 2023/03/11 21:29:55 by nimai            ###   ########.fr       */
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


typedef struct s_line
{
	void			*content;
	struct s_line	*next;
	struct s_line	*prev;
}	t_line;

typedef struct s_fdf
{
	void			*content;
	struct s_line	*row[ARGLIMIT];//kore de ii ki ga suru no se
	struct s_line	*column[ARGLIMIT];
    int             row_size;
    int             clm_size;
}	t_fdf;

int	main(int ac, char **av);
//int main(void);
int	fdf_error(int type);

#endif
