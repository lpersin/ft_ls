/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:03:15 by lpersin           #+#    #+#             */
/*   Updated: 2019/06/13 17:03:20 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_paths_lst(t_list *paths_lst)
{
	while (paths_lst != NULL)
	{
		ft_putstr(((t_entry*)paths_lst->content)->name);
		ft_putstr("\n");
		paths_lst = paths_lst->next;
	}
}

void print_dir_path(char *path, int one_entry)
{
	if(!one_entry)
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
}