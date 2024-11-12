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
	size_t		word_index;
	size_t		char_index;
	size_t		word_len;
	char		**split_str;
	const int	count = word_count(s, c);

	if (!s)
		return (NULL);
	split_str = ft_calloc(count + 1, sizeof(char *));
	if (!split_str)
		return (NULL);
	word_index = 0;
	char_index = 0;
	word_len = 0;
	while (word_index < count)
	{
		while (s[char_index] == c)
			char_index++;
		word_len = ft_strchr(s, c) - &s[char_index];
		split_str[word_index] = ft_substr(s, char_index, word_len);
		char_index = char_index + word_len;
		word_index++;
	}
	return (split_str);
}
