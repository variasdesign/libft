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

static void	free_matrix(void)
{
}

char	**ft_split(const char *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		word_len;
	char		**split_str;
	const int	count = word_count(s, c);

	if (!s)
		return (NULL);
	split_str = ft_calloc(count + 1, sizeof(char *));
	if (!split_str)
		return (NULL);
	i = 0;
	j = 0;
	word_len = 0;
	while (i < count + 1)
	{
		while (s[j] == c)
			j++;
		word_len = ft_strchr(s, c) - &s[j];
		split_str[i] = ft_substr(s, j, word_len);
		j = j + word_len;
		i++;
	}
	return (split_str);
}
