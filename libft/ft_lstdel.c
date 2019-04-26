/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:53:53 by lpersin           #+#    #+#             */
/*   Updated: 2018/06/28 14:08:40 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *node;
	t_list *tmp;

	node = *alst;
	if (alst && node)
	{
		while (node)
		{
			tmp = node;
			(*del)(tmp->content, tmp->content_size);
			free(tmp);
			node = node->next;
		}
		*alst = NULL;
	}
}
