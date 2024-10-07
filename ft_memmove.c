/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:07:26 by varias-c          #+#    #+#             */
/*   Updated: 2024/10/01 18:40:30 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp_dst;
	char	*temp_src;
	size_t	i;

	if (src == NULL && dst == NULL)
		return (NULL);
	temp_dst = (char *) dst;
	temp_src = (char *) src;
	i = 0;
	if (temp_dst > temp_src)
		while (len-- > 0)
			temp_dst[len] = temp_src[len];
	else
		while (i++ < len)
			temp_dst[i] = temp_src[i];
	return (dst);
}
