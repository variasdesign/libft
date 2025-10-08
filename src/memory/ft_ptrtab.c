/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:26:23 by varias-c          #+#    #+#             */
/*   Updated: 2025/10/08 20:47:22 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Check if ptr is inside start and end of any pointer range in table
// TODO: Binary search to optimize times
ssize_t	ft_tabfind(void *ptr, t_ptr_tab tab)
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

// TODO: Needs some rethinking. It needs to nullify the tail end, right now
// it's duplicating it.
void	*ft_tabdelone(t_bool start_or_end, ssize_t i, t_ptr_tab *tab)
{
	ssize_t	j;

	j = i;
	tab->count--;
	if (!start_or_end)
	{
		tab->start[j] = tab->end[j] - 1;
		while (tab->start[++j])
		{
			tab->end[j - 1] = tab->start[j] + 1;
			tab->start[j] = tab->end[j] - (tab->end[j] != 0);
		}
		
		return (tab->start[i]);
	}
	else
	{
		while (tab->start[++j])
		{
			tab->end[j - 1] = tab->start[j] + 1;
			tab->start[j] = tab->end[j] - (tab->end[j] != 0);
		}
		return (tab->end[i]);
	}
}

t_ptr_tab	*ft_taballoc(t_ptr_tab *tab, char *orig, size_t size)
{
	tab->orig = orig;
	tab->read = orig;
	tab->start = ft_calloc(tab->count + 1, size);
	if (!tab->start)
	{
		free (tab);
		return (NULL);
	}
	tab->end = ft_calloc(tab->count + 1, size);
	if (!tab->end)
	{
		free (tab->start);
		free (tab);
		return (NULL);
	}
	return (tab);
}
