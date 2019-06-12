/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:47:01 by lpersin           #+#    #+#             */
/*   Updated: 2018/06/28 14:00:55 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list *node;

	node = *alst;
	if (alst && node)
	{
		(*del)(node->content, node->content_size);
		free(node->content);
		node->content = NULL;
		free(node);
		*alst = NULL;
	}
}
