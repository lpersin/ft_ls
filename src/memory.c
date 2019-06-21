/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:02:45 by lpersin           #+#    #+#             */
/*   Updated: 2019/06/21 16:20:18 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_entry(void *v_entry, size_t content_size)
{
	t_entry *entry;

	entry = (t_entry*)v_entry;
	if (content_size)
	{
		ft_memdel((void**)&(entry->name));
		ft_memdel((void**)&(entry->stat));
		ft_memdel((void**)&(entry->full_path));
		ft_memdel((void**)&(entry));
	}
}

void	free_entries_lst(t_list **entries_lst)
{
	t_list *tmp_node;

	while (*entries_lst != NULL)
	{
		tmp_node = (*entries_lst)->next;
		free_entry((void*)(*entries_lst)->content,
				(*entries_lst)->content_size);
		free(*entries_lst);
		*entries_lst = tmp_node;
	}
}

void	init_options(t_options *options)
{
	if (options != NULL)
	{
		options->a = 0;
		options->l = 0;
		options->loaded = 0;
		options->rec = 0;
		options->r = 0;
		options->t = 0;
	}
}
