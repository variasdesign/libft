/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:51:57 by varias-c          #+#    #+#             */
/*   Updated: 2024/10/01 18:06:10 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	if (src == NULL && dst == NULL)
		return (dst);
	temp_dst = (unsigned char *) dst;
	temp_src = (unsigned char *) src;
	while (n > 0)
	{
		*temp_dst = *temp_src;
		temp_dst++;
		temp_src++;
		n--;
	}
	return (dst);
}
