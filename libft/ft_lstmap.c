/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:15:47 by lpersin           #+#    #+#             */
/*   Updated: 2018/06/29 14:05:00 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *new_node;
	t_list *head;
	t_list *next_node;

	head = NULL;
	if (lst && (*f))
	{
		new_node = (*f)(lst);
		if (new_node)
		{
			head = new_node;
			lst = lst->next;
			while (lst)
			{
				next_node = (*f)(lst);
				if (!next_node)
					return (NULL);
				new_node->next = next_node;
				new_node = next_node;
				lst = lst->next;
			}
		}
	}
	return (head);
}
