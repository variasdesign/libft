/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:26:23 by varias-c          #+#    #+#             */
/*   Updated: 2025/10/13 12:33:57 by varias-c         ###   ########.fr       */
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

ssize_t	ft_tabptrlen(ssize_t i, t_ptr_tab tab)
{
	if (tab.start[i] && tab.end[i])
		return (tab.end[i] - tab.start[i]);
	return (-1);
}
