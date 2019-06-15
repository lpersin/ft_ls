/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha_sortlst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:25:13 by lpersin           #+#    #+#             */
/*   Updated: 2019/06/11 14:20:05 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	front_back_split(t_list *source, t_list **front_ref,
								t_list **back_ref)
{
	t_list *fast;
	t_list *slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = NULL;
}

static	t_list	*sorted_merge(t_list *a, t_list *b)
{
	t_list *result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if ((ft_strcmp((char*)a->content, (char*)b->content) <= 0))
	{
		result = a;
		result->next = sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next);
	}
	return (result);
}

void			ft_alpha_sortlst(t_list **head_ref)
{
	t_list *head;
	t_list *a;
	t_list *b;

	head = *head_ref;
	if (head == NULL || head->next == NULL)
		return ;
	front_back_split(head, &a, &b);
	ft_alpha_sortlst(&a);
	ft_alpha_sortlst(&b);
	*head_ref = sorted_merge(a, b);
}
