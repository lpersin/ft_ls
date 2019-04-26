/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:41:12 by lpersin           #+#    #+#             */
/*   Updated: 2018/07/04 17:21:41 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *node;

	node = (t_list*)malloc(sizeof(*node));
	if (node)
	{
		if (content == NULL)
		{
			node->content = NULL;
			node->content_size = 0;
			node->next = NULL;
		}
		else
		{
			node->content = ft_memalloc(content_size);
			if (!node->content)
				return (NULL);
			else
			{
				ft_memcpy(node->content, content, content_size);
				node->content_size = content_size;
				node->next = NULL;
			}
		}
	}
	return (node);
}
