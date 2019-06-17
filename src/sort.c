/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:03:29 by lpersin           #+#    #+#             */
/*   Updated: 2019/06/13 17:03:31 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	alpha_sort(t_list* a, t_list* b)
{
	return (ft_strcmp(((t_entry*)a->content)->name, 
				((t_entry*)b->content)->name));
}

int last_modif_time_sort(t_list* a, t_list*b)
{
	long res;

	res = (long) ((t_entry*)a->content)->stat->st_mtimespec.tv_sec - 
			((t_entry*)b->content)->stat->st_mtimespec.tv_sec;
	 if (res == 0)
	 {
	 	res = ft_strcmp(((t_entry*)b->content)->name, 
	 			((t_entry*)a->content)->name);
	}
	return (res);
}

int is_dot_entry(t_list *node)
{
	return (((t_entry*)node->content)->name[0] == '.');
}

void sort_entries(t_list **entries_lst, t_options* const options, char user_path)
{
	if (options->a == 0 && !user_path)
		*entries_lst = ft_lst_del_occurences(*entries_lst, is_dot_entry, free_entry);
	if (options->t == 1)
	{
		ft_fct_sortlst(entries_lst, last_modif_time_sort);
		ft_lstrev(entries_lst);
	}
	else
		ft_fct_sortlst(entries_lst, alpha_sort);
	if (options->r == 1)
		ft_lstrev(entries_lst);
}
