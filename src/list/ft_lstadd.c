/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:01:32 by varias-c          #+#    #+#             */
/*   Updated: 2025/05/28 18:10:55 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list *list, t_node *new_node)
{
	if (!list || !new_node)
		return ;
	if (list->head)
		new_node->next = list->head;
	list->head = new_node;
	list->count++;
}

void	ft_lstadd_back(t_list *list, t_node *new_node)
{
	if (!list || !new_node)
		return ;
	if (!list->head)
	{
		list->head = new_node;
		list->tail = new_node;
	}
	else
	{
		list->tail->next = new_node;
	}
	list->count++;
}

// Insert after
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
		if (!new_node->next)
			list->tail = new_node;
	}
	list->count++;
}
