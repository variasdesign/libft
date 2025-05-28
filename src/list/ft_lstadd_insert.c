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

void	ft_lstadd_insert(t_list *list, t_node *new_node, ssize_t pos)
{
	t_node	*node;

	if (!list || !new_node || pos < 0)
		return ;
	if (!list->head)
		list->head = new_node;
	else
	{
		node = list->head;
		while (pos > 0)
		{
			if (node->next)
				node = node->next;
			else
				break ;
			pos--;
		}
		new_node->next = node->next;
		node->next = new_node;
	}
	list->count++;
}
