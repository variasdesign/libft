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

void	ft_tabmovebackall (ssize_t i, t_ptr_tab *tab)
{
	while (tab->start[i++])
	{
		tab->end[i - 1] = tab->start[i] + (tab->start[i] != NULL);
		tab->start[i] = tab->end[i] - (tab->end[i] != NULL);
	}
	tab->count -= !tab->start[tab->count - 1];
}

void	*ft_tabdelone(t_bool start_or_end, ssize_t i, t_ptr_tab *tab)
{
	if (!start_or_end)
	{
		tab->start[i] = tab->end[i] - 1;
		ft_tabmovebackall(i, tab);
		return (tab->start[i]);
	}
	else
	{
		ft_tabmovebackall(i, tab);
		return (tab->end[i]);
	}
}

t_ptr_tab	*ft_tabfree(t_ptr_tab *tab)
{
	ft_freematrix(tab->start);
	tab->start = NULL;
	ft_freematrix(tab->end);
	tab->end = NULL;
	free(tab);
	tab = NULL;
	return (tab);
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
