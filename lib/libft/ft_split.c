/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:33:35 by nimai             #+#    #+#             */
/*   Updated: 2023/03/01 15:04:35 by nimai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>//kesu

int	word_nbr(char const *str, char c)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i] && str[i] != 10)
	{
		if (str[i] && str[i] != c)
			ret++;
		while (str[i] && str[i] != c)
			i++;
		while (str[i] == c)
			i++;
	}
	return (ret);
}

int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**free_error(char **tab, int i)
{
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	len;

	i = 0;
	tab = (char **) malloc(sizeof(char *) * (word_nbr(s, c) + 1));
	printf("Line: %d, word_nbr: %d\n", __LINE__, word_nbr(s, c));
	if (!tab)
		return (NULL);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		len = word_len(s, c) + 1;
		tab[i] = (char *)malloc(sizeof(char *) * len);
		if (!tab[i])
			return (free_error(tab, i));
		ft_strlcpy(tab[i], s, len);
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		printf("Line: %d, tab[%zu]: %p, str: %s\n", __LINE__, i, tab[i], tab[i]);
		i++;
	}
	tab[i] = NULL;
	printf("Line: %d, tab[%zu]: %p\n", __LINE__, i, tab[i]);
	return (tab);
}
