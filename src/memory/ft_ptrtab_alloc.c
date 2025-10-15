/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtab_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:30:19 by varias-c          #+#    #+#             */
/*   Updated: 2025/10/13 12:36:22 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ptr_tab	*ft_tabfree(t_ptr_tab *tab)
{
	if (tab)
	{
		if (tab->start)
			free(tab->start);
		tab->start = NULL;
		if (tab->end)
			free(tab->end);
		tab->end = NULL;
		free(tab);
		tab = NULL;
	}
	return (tab);
}

t_ptr_tab	*ft_taballoc(t_ptr_tab *tab, char *orig, size_t size)
{
	tab->size = size;
	tab->orig = orig;
	tab->read = orig;
	tab->start = ft_calloc(tab->count + 1, tab->size);
	if (!tab->start)
	{
		free (tab);
		return (NULL);
	}
	tab->end = ft_calloc(tab->count + 1, tab->size);
	if (!tab->end)
	{
		free (tab->start);
		free (tab);
		return (NULL);
	}
	return (tab);
}
