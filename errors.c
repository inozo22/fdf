/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:36:39 by nimai             #+#    #+#             */
/*   Updated: 2023/03/11 16:41:49 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_error(int type)
{
	if (type == 1)//error memory release unnecessary
	{
		ft_putstr_fd("error without memory", 1);
		return (0);
	}

}
