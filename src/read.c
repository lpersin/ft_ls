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

void	read_dir(char *path, t_list **paths_lst, char *error)
{
	DIR *dir_p;
	struct dirent* dp;

	if((dir_p = opendir(path)) != NULL)
	{
		while ((dp = readdir(dir_p)) != NULL)
		{
			load_entry(dp->d_name, paths_lst, path);
		}
		closedir(dir_p);
	}
	else
	{
		*error = 1;
		show_error(path, 0);
	}
}

char *full_path(char *path, char* suffix)
{
	char *str;
	char *tmp;

	str = NULL;
	tmp = NULL;
	if(suffix == NULL)
		return ft_strdup(path);
	if((str = ft_strjoin(suffix, "/")) != NULL)
	{
		tmp = str;
		str = ft_strjoin(str, path);
	}
	free(tmp);

	return str;
}

t_entry	*get_t_entry(char *entry_name, char *path)
{
	t_entry	*entry;
	char	*full_path_str;

	entry = NULL;
	if (entry_name != NULL)
	{
		full_path_str = full_path(entry_name, path);
		if ((entry = (t_entry*)malloc(sizeof(t_entry))) == NULL)
			show_error(entry_name, 1);
		if ((entry->name = ft_strdup(entry_name)) == NULL)
			show_error(entry_name, 1);
		if((entry->stat = (struct stat*)malloc(sizeof(struct stat))) == NULL)
			show_error(entry_name, 1);
		stat(full_path_str, entry->stat);
		free(full_path_str);
	}
	return entry;
}

void load_entry(char *entry_name, t_list** paths_lst, char *path)
{
	t_list*		node;
	t_entry*	entry;

	entry = get_t_entry(entry_name, path);
	if ((node = ft_lstnew(entry, sizeof(t_entry))) == NULL)
		show_error(entry_name, 1);
	if (*paths_lst == NULL)
		*paths_lst = node;
	else
		ft_lstadd(paths_lst, node);
	free(entry);
}
