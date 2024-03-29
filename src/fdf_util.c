/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:27:24 by nimai             #+#    #+#             */
/*   Updated: 2023/04/18 12:02:24 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	get_colour(char *str, int i, int row, t_f *f)
{
	char	tmp[20];
	int		j;

	j = 0;
	++i;
	if (str[i] != '0' || (str[i + 1] != 'x'))
		exit (hollow_error(2));
	i = i + 2;
	while (str[i] && str[i] != 32)
	{
		tmp[j] = str[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	f->n[f->column][row].colour = hexatoi(tmp);
	return (i);
}

bool	check_amount(t_f *f, int ret)
{
	if (f->is_first)
	{
		f->row_len = ret;
		f->is_first = 0;
	}
	else
	{
		if (ret != f->row_len)
			return (false);
	}
	return (true);
}

int	count_word(char *str, t_f *f)
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
			i = get_colour(str, i, ret - 1, f);
		while (str[i] == 32 || str[i] == 't')
			i++;
	}
	if (!check_amount(f, ret))
		exit(hollow_error(2));
	return (ret);
}
