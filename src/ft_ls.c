/* *********************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:01:31 by lpersin           #+#    #+#             */
/*   Updated: 2019/06/11 15:49:20 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void default_ls(t_list *paths_lst, t_options* const options)
{
		read_dir(".", &paths_lst);
		sort_entries(&paths_lst, options, 0);
		print_paths_lst(paths_lst);
		free_entries_lst(&paths_lst);
}

void options_ls(t_list *paths_lst, t_options* const options, int one_entry)
{
	t_list *current_entries;
	t_list *head;
	t_list *tmp_node;

	head = paths_lst;
	current_entries = NULL;
	while(paths_lst != NULL)
	{
		read_dir(((t_entry*)paths_lst->content)->name, &current_entries); 
		sort_entries(&current_entries, options, 0);
		print_dir_path(((t_entry*)paths_lst->content)->name, one_entry);
		print_paths_lst(current_entries);
		if (paths_lst->next != NULL)
			ft_putstr("\n");
		if(options->R)
		{
			tmp_node = current_entries; 
			while (tmp_node != NULL)
			{
				if (is_dir(tmp_node))
					options_ls(tmp_node, options, 0);
				tmp_node = tmp_node->next;
			}
		}
		free_entries_lst(&current_entries);
		paths_lst = paths_lst->next;
	}
	free_entries_lst(&head);
}

int main(int argc, char **argv)
{
	t_list *paths_lst;
	t_options *options;

	paths_lst = NULL;
	if((options = (t_options*)malloc(sizeof(t_options)))== NULL)
		show_error("args", 1);
	init_options(options);
	if (argc > 1)
	{
		get_args(argc, argv, options, &paths_lst);
		sort_entries(&paths_lst, options, 1);
		options_ls(paths_lst, options, (paths_lst->next == NULL));
	}
	else
		default_ls(paths_lst, options);
	free(options);
/*
	DIR *dir_p = opendir(".");
	struct dirent* dp;

	ft_putnbr(ft_strcmp("a", "b"));
	while ((dp = readdir(dir_p)) != NULL)
	{
		ft_putstr(dp->d_name);
		ft_putnbr(dp->d_namlen);
		ft_putstr("\n");
	}

	char *buf_mode = ft_strnew(9);
	struct stat *buf = (struct stat*)malloc(sizeof(struct stat));
	stat("/home/trokadero/Documents", buf);
	get_mode(buf->st_mode, buf_mode);
	//ft_putstr("\nNom: "); ft_putstr("test");
	//ft_putstr("\nType: "); ft_putchar(get_type(buf->st_mode));
	//ft_putstr("\nModes: "); ft_putstr(buf_mode);
	//ft_putstr("\nNb liens: "); ft_putnbr((int) buf->st_nlink);
	//ft_putstr("\nProprietaire: "); ft_putstr(getpwuid(buf->st_uid)->pw_name);
	//ft_putstr("\nGroupe: "); ft_putstr(getgrgid(buf->st_gid)->gr_name);
	//ft_putstr("\nTaille: "); ft_putnbr((int) buf->st_size);
	char *date = ft_strnew(12);
	format_time(ctime(&(buf->st_mtime)), date);
	ft_putstr("\nDate de derniere modification: "); ft_putstr(date);//ft_putstr(ctime(&(buf->st_mtim.tv_sec)));
	*/
	return(0);
}
