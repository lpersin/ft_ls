/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lprint2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 18:31:45 by lpersin           #+#    #+#             */
/*   Updated: 2019/06/21 18:32:12 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	get_max_links_count(t_list *node)
{
	int res;
	int candidate;

	res = 0;
	while (node != NULL)
	{
		candidate = (((t_entry*)node->content)->stat->st_nlink);
		if (candidate > res)
			res = candidate;
		node = node->next;
	}
	return (res);
}

size_t	get_max_bytes_count(t_list *node)
{
	int res;
	int candidate;

	res = 0;
	while (node != NULL)
	{
		candidate = (((t_entry*)node->content)->stat->st_size);
		if (candidate > res)
			res = candidate;
		node = node->next;
	}
	return (res);
}

size_t	get_total_blks_allocated(t_list *node)
{
	int res;

	res = 0;
	while (node != NULL)
	{
		res += ((t_entry*)node->content)->stat->st_blocks;
		node = node->next;
	}
	return (res);
}

int		l_min_str_size(t_list *node)
{
	int		res;
	t_entry	*entry;

	entry = (t_entry*)node->content;
	res = 9 + 2 + ft_count_digits(get_max_links_count(node)) + 1
				+ ft_strlen(getpwuid(entry->stat->st_uid)->pw_name) + 2
				+ ft_strlen(getgrgid(entry->stat->st_gid)->gr_name) + 2
				+ ft_count_digits(get_max_bytes_count(node)) + 1 + 12 + 1;
	return (res);
}

int		get_longest_username(t_list *node)
{
	int		res;
	int		candidate;
	t_entry	*entry;

	res = 0;
	while (node != NULL)
	{
		entry = (t_entry*)node->content;
		candidate = ft_strlen(getpwuid(entry->stat->st_uid)->pw_name);
		if (candidate > res)
			res = candidate;
		node = node->next;
	}
	return (res);
}
