/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:13:13 by varias-c          #+#    #+#             */
/*   Updated: 2025/05/28 18:22:16 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_list(t_list *list, void (*del)(void *))
{
	t_node	*node;

	if (!list || !list->head || !del)
		return ;
	node = list->head;
	while (node)
	{
		list->head = node->next;
		ft_lstdel_node(node, del);
		list->count--;
		node = list->head;
	}
	free(list);
}
