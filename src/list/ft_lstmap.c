/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varias-c <varias-c@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:22:51 by varias-c          #+#    #+#             */
/*   Updated: 2025/01/11 17:22:52 by varias-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	void	*current;

	new_lst = NULL;
	while (lst)
	{
		current = f(lst->content);
		new_elem = ft_lstnew(current);
		if (!new_elem)
		{
			del(current);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	lst = NULL;
	return (new_lst);
}

/* int main () */
/* { */
/* 	t_list *lst; */
/* 	t_list *lstlen; */
/**/
/* 	lst = ft_lstnew(ft_strdup("hello!")); */
/* 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("how are you"))); */
/* 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("life is suffering"))); */
/* 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("oh look a cat"))); */
/* 	lstlen = ft_lstmap(lst, (void *)ft_strlen, free); */
/* 	ft_lstclear(&lst, free); */
/* } */
