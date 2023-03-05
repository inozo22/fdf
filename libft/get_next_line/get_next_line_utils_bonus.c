/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:30:22 by nimai             #+#    #+#             */
/*   Updated: 2023/02/18 19:30:22 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *memo, char *buff)
{
	ssize_t	i;
	ssize_t	c;
	char	*ret;

	if (!memo)
	{
		memo = (char *)malloc(1 * sizeof(char));
		memo[0] = '\0';
	}
	if (!memo || !buff)
		return (NULL);
	ret = malloc(ft_strlen(memo) + ft_strlen(buff) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	c = 0;
	while (memo[++i] != '\0')
		ret[i] = memo[i];
	while (buff[c] != '\0')
		ret[i++] = buff[c++];
	ret[i] = '\0';
	free(memo);
	return (ret);
}

char	*get_ret(char *memo)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!memo[i])
		return (NULL);
	while (memo[i] && memo[i] != '\n')
		i++;
	if (memo[i] == '\n')
		ret = (char *)malloc((i + 2) * sizeof(char));
	else
		ret = (char *)malloc((i + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (memo[i] && memo[i] != '\n')
	{
		ret[i] = memo[i];
		i++;
	}
	if (memo[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

char	*crop_memo(char *memo)
{
	size_t		i;
	size_t		c;
	char		*ret;

	i = 0;
	while (memo[i] && memo[i] != '\n')
		i++;
	if (!memo[i])
	{
		free(memo);
		return (NULL);
	}
	ret = (char *)malloc((ft_strlen(memo) - i + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i++;
	c = 0;
	while (memo[i])
		ret[c++] = memo[i++];
	ret[c] = '\0';
	free(memo);
	return (ret);
}
