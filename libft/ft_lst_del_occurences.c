/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_occurences.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:38:40 by lpersin           #+#    #+#             */
/*   Updated: 2019/06/11 15:43:11 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lst_del_occurences(t_list *head, int (*target)(t_list*), 
								void (*del)(void*, size_t))
{
	t_list *tmp_node;

	if (head == NULL)
		return NULL;
	if ((*target)(head))
	{
		ft_putstr("SHEH\n");
		tmp_node = head->next;
		(*del)(head->content, head->content_size);
		free(head);
		return ft_lst_del_occurences(tmp_node, target, del);
	}
	head->next = ft_lst_del_occurences(head->next, target, del);
	return head;
}
