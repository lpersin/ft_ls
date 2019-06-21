/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_occurences.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:38:40 by lpersin           #+#    #+#             */
/*   Updated: 2019/06/21 15:58:49 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_del_occurences(t_list *head, int (*target)(t_list*),
								void (*del)(void*, size_t))
{
	t_list *tmp_node;

	tmp_node = NULL;
	if (head == NULL)
		return (NULL);
	if ((*target)(head))
	{
		tmp_node = head->next;
		(*del)(head->content, head->content_size);
		free(head);
		head = NULL;
		return (ft_lst_del_occurences(tmp_node, target, del));
	}
	head->next = ft_lst_del_occurences(head->next, target, del);
	return (head);
}
