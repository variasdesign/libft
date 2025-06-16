/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:40:18 by varias-c          #+#    #+#             */
/*   Updated: 2025/06/16 19:33:21 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstfind_content_int(t_list *list, void *data)
{
	t_node	*node;

	node = list->head;
	while (node->next != NULL)
	{
		if (*(int *)node->content == *(int *)data)
			return (node);
		node = node->next;
	}
	return (NULL);
}

ssize_t ft_lstfind_pos(t_list *list, t_node *node_to_find)
{
	ssize_t	i;
	t_node	*node;

	if (!list)
		return (-1);
	i = 0;
	node = list->head;
	while (node != node_to_find || !(i < list->count))
	{
		i++;
		node = node->next;
	}
	if (i < list->count)
		return (i);
	return (-1);
}

t_node	*ft_lstfind_index(t_list *list, ssize_t index)
{
	ssize_t	i;
	t_node	*node;

	if (!list || !(index < list->count))
		return (NULL);
	node = list->head;
	i = 0;
	while (node != NULL)
	{
		if (i == index)
			return (node);
		node = node->next;
		i++;
	}
	return (NULL);
}
