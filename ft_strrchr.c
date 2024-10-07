/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:14:20 by varias-c          #+#    #+#             */
/*   Updated: 2024/10/03 18:44:20 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	char			*lastchr;

	lastchr = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			lastchr = (char *) &s[i];
		i++;
	}
	if (s[i] == c)
		lastchr = (char *) &s[i];
	return (lastchr);
}
