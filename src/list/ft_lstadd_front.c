/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:33:18 by varias-c          #+#    #+#             */
/*   Updated: 2025/05/26 23:14:12 by varias-c         ###   ########.fr       */
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
