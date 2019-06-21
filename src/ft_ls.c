/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:02:12 by lpersin           #+#    #+#             */
/*   Updated: 2019/06/21 18:31:20 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*load_full_path(t_list *node, char *str)
{
	t_entry	*entry;
	char	*tmp;

	entry = (t_entry*)node->content;
	tmp = entry->name;
	entry->name = full_path(entry->name, str);
	free(tmp);
	return (node);
}

void	options_ls(char *path, t_options *const options, int one_entry)
{
	t_list	*current_entries;
	char	error;

	error = 0;
	current_entries = NULL;
	print_dir_path(path, one_entry);
	read_dir(path, &current_entries, &error);
	sort_entries(&current_entries, options, 0);
	if (options->l && current_entries != NULL)
	{
		ft_putstr("total ");
		ft_putnbr(get_total_blks_allocated(current_entries));
		ft_putstr("\n");
	}
	if (options->l)
		l_print(current_entries, 0);
	else
		print_paths_lst(current_entries);
	if (!error && current_entries != NULL)
		ft_putstr("\n");
	if (options->rec)
		recursive_ls(path, current_entries, options);
	free_entries_lst(&current_entries);
}

void	recursive_ls(char *path, t_list *current_entries, t_options *const opt)
{
	char	*tmp_path;

	while (current_entries != NULL)
	{
		if (!is_dot_dir(current_entries))
		{
			current_entries = load_full_path(current_entries, path);
			tmp_path = ((t_entry*)current_entries->content)->name;
		}
		if (is_dir(current_entries) && !is_dot_dir(current_entries)
				&& !is_symlink(current_entries))
		{
			ft_putstr("\n");
			options_ls(tmp_path, opt, 0);
		}
		current_entries = current_entries->next;
	}
}

int		main(int argc, char **argv)
{
	t_list		*paths_lst;
	t_options	*options;
	int			single_entry;

	paths_lst = NULL;
	if ((options = (t_options*)malloc(sizeof(t_options))) == NULL)
		show_error("args", 1);
	init_options(options);
	get_args(argc, argv, options, &paths_lst);
	if (paths_lst == NULL)
		load_entry(".", &paths_lst, NULL);
	single_entry = (paths_lst->next == NULL);
	paths_lst = parse_user_args(&paths_lst, options);
	if (paths_lst != NULL)
	{
		sort_entries(&paths_lst, options, 1);
		ft_ls(paths_lst, options, single_entry);
	}
	free(options);
	return (0);
}

void	ft_ls(t_list *paths_lst, t_options *options, int single_entry)
{
	t_list	*head;

	head = paths_lst;
	while (paths_lst != NULL)
	{
		options_ls(((t_entry*)paths_lst->content)->name,
				options, single_entry);
		if (paths_lst->next != NULL)
			ft_putstr("\n");
		paths_lst = paths_lst->next;
	}
	free_entries_lst(&head);
}
