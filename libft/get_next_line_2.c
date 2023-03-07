/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:28:44 by nimai             #+#    #+#             */
/*   Updated: 2023/02/18 19:28:44 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*gnl_strchr(char *s, int c)
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

char	*read_memo(int fd, char *memo, char	*buff)
{
	ssize_t	ret_read;

	ret_read = 1;
	while (ret_read > 0 && !gnl_strchr(memo, '\n'))
	{
		ret_read = read(fd, buff, BUFFER_SIZE);
		if (ret_read == -1)
		{
			free(buff);
			free(memo);
			return (NULL);
		}
		buff[ret_read] = '\0';
		if (!memo)
		{
			memo = (char *)malloc(1 * sizeof(char));
			memo[0] = '\0';
		}
		if (!memo || !buff)
		{
/* 			free(buff);
			free(memo); */
			return (NULL);
		}
		memo = ft_strjoin(memo, buff);
	}
	printf("memo: %p\n", memo);
	printf("bufff: %p\n", buff);
	free(buff);
	return (memo);
}

char	*get_next_line(int fd)
{
	static char	*memo[1024];
	char		*ret;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	memo[fd] = read_memo(fd, memo[fd], buff);
	if (!memo[fd])
	{
		free(buff);
		return (NULL);
	}
	ret = get_ret(memo[fd]);
	memo[fd] = crop_memo(memo[fd]);
	return (ret);
}
