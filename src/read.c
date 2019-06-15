/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:03:23 by lpersin           #+#    #+#             */
/*   Updated: 2019/06/13 17:03:26 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	read_dir(char *path, t_list **paths_lst)
{
	DIR *dir_p;
	struct dirent* dp;

	if((dir_p = opendir(path)) != NULL)
	{
		while ((dp = readdir(dir_p)) != NULL)
		{
			load_entry(dp->d_name, paths_lst);
		}
		closedir(dir_p);
	}
	else
		show_error(path, 0);
}


char *full_path(char *path, char* suffix)
{
	char *str;

	if(suffix == NULL)
		return path;
	str = ft_strjoin(suffix, "/");
	str = ft_strjoin(str, path);

	return str;
}

t_entry	*get_t_entry(char *path)
{
	t_entry	*entry;

	entry = NULL;
	if (path != NULL)
	{
		if ((entry = (t_entry*)malloc(sizeof(t_entry))) == NULL)
			show_error(path, 1);
		if ((entry->name = ft_strdup(path)) == NULL)
			show_error(path, 1);
		if((entry->stat = (struct stat*)malloc(sizeof(struct stat))) == NULL)
			show_error(path, 1);
		stat(path, entry->stat);
	}
	return entry;
}

void load_entry(char *path, t_list** paths_lst)
{
	t_list*		node;
	t_entry*	entry;

	entry = get_t_entry(path);
	if ((node = ft_lstnew(entry, sizeof(t_entry))) == NULL)
		show_error(path, 1);
	if (*paths_lst == NULL)
		*paths_lst = node;
	else
		ft_lstadd(paths_lst, node);
	free(entry);
}
