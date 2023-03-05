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

#include "../includes/get_next_line_bonus.h"

char	*read_memo(int fd, char *memo)
{
	char	*buff;
	ssize_t	ret_read;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	ret_read = 1;
	while (ret_read > 0 && !ft_strchr(memo, '\n'))
	{
		ret_read = read(fd, buff, BUFFER_SIZE);
		if (ret_read == -1)
		{
			free(buff);
			free(memo);
			return (NULL);
		}
		buff[ret_read] = '\0';
		memo = ft_strjoin(memo, buff);
	}
	free(buff);
	return (memo);
}

char	*get_next_line(int fd)
{
	static char	*memo[1024];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	memo[fd] = read_memo(fd, memo[fd]);
	if (!memo[fd])
		return (NULL);
	ret = get_ret(memo[fd]);
	memo[fd] = crop_memo(memo[fd]);
	return (ret);
}
