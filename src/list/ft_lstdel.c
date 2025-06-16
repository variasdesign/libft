/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:13:13 by varias-c          #+#    #+#             */
/*   Updated: 2025/06/16 20:42:01 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_pos(t_list *list, void (*del)(void *), ssize_t pos)
{
	if (pos > list->count)
		return ;
	ft_lstdel_node(list, ft_lstfind_index(list, pos), del);
}

void	ft_lstdel_node(t_list *list, t_node *node, void (*del)(void *))
{
	if (!node || !del)
		return ;
	if (node->next)
		node->next->prev = node->prev;
	else if (node->prev)
		node->prev->next = node->next;
	if (list->head == node)
		list->head = node->next;
	if (list->tail == node)
		list->tail = node->prev;
	del(node->content);
	free(node);
	list->count--;
}

void	ft_lstdel_list(t_list *list, void (*del)(void *))
{
	t_node	*node;

	if (!list || !list->head || !del)
		return ;
	node = list->head;
	while (node)
	{
		list->head = node->next;
		ft_lstdel_node(list, node, del);
		node = list->head;
	}
	free(list);
}
