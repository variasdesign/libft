/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:55:42 by varias-c          #+#    #+#             */
/*   Updated: 2024/11/09 19:22:00 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	word_count(const char *s, const char c)
{
	size_t	i;
	int		count;

	count = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	return (count);
}

static char	**free_matrix(char **split_str, const int count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free((void *)split_str[i]);
		i++;
	}
	free((void *)split_str);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	size_t		word_i;
	size_t		char_i;
	char		**split_str;
	const int	count = word_count(s, c);

	if (!s)
		return (NULL);
	split_str = ft_calloc(count + 1, sizeof(char *));
	if (!split_str)
		return (free_matrix(split_str, count));
	word_i = 0;
	char_i = 0;
	while (word_i < count)
	{
		while (s[char_i] == c)
			char_i++;
		split_str[word_i] = ft_substr(s, char_i, ft_strchr(s, c) - &s[char_i]);
		if (!split_str[word_i])
			return (free_matrix(split_str, count));
		char_i = char_i + ft_strchr(s, c) - &s[char_i];
		word_i++;
	}
	return (split_str);
}
