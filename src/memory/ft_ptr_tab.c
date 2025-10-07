/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:26:23 by varias-c          #+#    #+#             */
/*   Updated: 2025/10/06 19:42:00 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TODO: Binary search to optimize times
// Check if ptr is inside start and end of any pointer range
ssize_t	ft_inptrtab(void *ptr, t_ptr_tab tab)
{
	ssize_t	i;

	i = 0;
	while (i < tab.count && tab.start[i] && tab.end[i])
	{
		if (ptr > tab.start[i] && ptr < tab.end[i])
			return (i);
		i++;
	}
	return (-1);
}

void	ft_alloptrtab(t_ptr_tab *tab, char *orig, size_t size)
{
	tab->orig = orig;
	tab->read = orig;
	tab->start = ft_calloc(tab->count + 1, size);
	tab->end = ft_calloc(tab->count + 1, size);
}
