/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 23:12:26 by varias-c          #+#    #+#             */
/*   Updated: 2025/05/26 23:35:36 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_insert(t_list **list, t_list *new_node, ssize_t pos)
{
	t_list	*tmp;

	tmp = *list;
	if (!tmp)
		tmp = new_node;
	else
	{
		while (pos > 0)
		{
			if (tmp->next)
				tmp = tmp->next;
			else
				break ;
			pos--;
		}
		new_node->next = tmp->next;
		tmp->next = new_node;
	}
}
