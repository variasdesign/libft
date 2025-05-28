/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:13:13 by varias-c          #+#    #+#             */
/*   Updated: 2025/05/28 17:08:34 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list *list, void (*del)(void *))
{
	t_node	*node;
	t_node	*next;

	if (!list || !list->head || !del)
		return ;
	node = list->head;
	while (node)
	{
		next = node->next;
		ft_lstdelone(node, del);
		node = next;
		list->count--;
	}
}
