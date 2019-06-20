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

t_list *load_full_path(t_list *node, char *str)
{
	t_entry *entry;
	char	*tmp;

	entry = (t_entry*)node->content;
	tmp = entry->name;
	entry->name = full_path(entry->name, str);
	free(tmp);
	return node;
}

void options_ls(char *path, t_options* const options, int one_entry)
{
	t_list	*current_entries;
	char	error;

	error = 0;
	current_entries = NULL;
	
	print_dir_path(path, one_entry);
	read_dir(path, &current_entries, &error);
	sort_entries(&current_entries, options, 0);
	if(options->l && current_entries != NULL)
	{
		ft_putstr("total ");
		ft_putnbr(get_total_blks_allocated(current_entries));
		ft_putstr("\n");
	}
	if(options->l)
		l_print(current_entries, 0);
	else
		print_paths_lst(current_entries);
	if(!error && current_entries != NULL)
		ft_putstr("\n");
	if(options->R)
		recursive_ls(path, current_entries, options);
	free_entries_lst(&current_entries);
}

void	recursive_ls(char *path, t_list* current_entries, t_options* const options)
{
	char 	*tmp_path;

	while (current_entries != NULL)
	{
		if(!is_dot_dir(current_entries))
		{
			current_entries = load_full_path(current_entries, path);
			tmp_path = ((t_entry*)current_entries->content)->name;
		}
		if (is_dir(current_entries) && !is_dot_dir(current_entries) && !is_symlink(current_entries))
		{
			ft_putstr("\n");
			options_ls(tmp_path, options, 0);
		}
		current_entries = current_entries->next;
	}
}

size_t get_max_links_count(t_list *node)
{
	int res;
	int candidate;

	res = 0;
	while(node != NULL)
	{
		candidate = (((t_entry*)node->content)->stat->st_nlink);
		if(candidate > res)
			res = candidate;
		node = node->next;
	}
	return res;
}

size_t get_max_bytes_count(t_list *node)
{
	int res;
	int candidate;

	res = 0;
	while(node != NULL)
	{
		candidate = (((t_entry*)node->content)->stat->st_size);
		if(candidate > res)
			res = candidate;
		node = node->next;
	}
	return res;
}

size_t get_total_blks_allocated(t_list *node)
{
	int res;

	res = 0;
	while(node != NULL)
	{
		res += ((t_entry*)node->content)->stat->st_blocks;
		node = node->next;
	}
	return res;
}

int	l_min_str_size(t_list *node)
{
	int res;
	t_entry*	entry;

	entry = (t_entry*)node->content;
	res = 9 + 2 + ft_count_digits(get_max_links_count(node)) + 1 
				+ ft_strlen(getpwuid(entry->stat->st_uid)->pw_name) + 2 
				+ ft_strlen(getgrgid(entry->stat->st_gid)->gr_name) + 2
				+ ft_count_digits(get_max_bytes_count(node)) + 1 + 12 + 1;
	return res;
}

int get_longest_username(t_list *node)
{
	int			res;
	int			candidate;
	t_entry*	entry;

	res = 0;
	while(node != NULL)
	{
		entry = (t_entry*)node->content;
		candidate = ft_strlen(getpwuid(entry->stat->st_uid)->pw_name);
		if(candidate > res)
			res = candidate;
		node = node->next;
	}
	return res;
}

int	get_longest_groupname(t_list *node)
{
	int			res;
	int			candidate;
	t_entry*	entry;

	res = 0;
	while(node != NULL)
	{
		entry = (t_entry*)node->content;
		candidate = ft_strlen(getgrgid(entry->stat->st_gid)->gr_name);
		if(candidate > res)
			res = candidate;
		node = node->next;
	}
	return res;
}

// char *get_link_name(t_list* node)

// }

//Will have to get lstat for symlinks and print right info
// PATH_MAX

void write_to_buf(char **buf, char* str, int pre_offset, int post_offset)
{
	int i;

	i = 0;
	*buf += pre_offset;
	while(*str)
	{
		**buf = *str;
		*buf += 1;
		str++;
		i++;
	}
	while(post_offset > i)
	{
		**buf = ' ';
		*buf += 1;
		i++;
	}
}

void l_print(t_list *node, int single)
{
	t_entry *entry;
	char*	str;
	int		str_len;
	int		min_len;
	t_list	*head;
	char*	orig_str;

	head = node;
	if(node != NULL)
		min_len = l_min_str_size(node);
	while(node != NULL)
	{
		
		entry = ((t_entry*)node->content);
		str_len = min_len + ft_strlen(entry->name) + 2;
		str = ft_strnew(str_len);
		orig_str = str;
		ft_strfill(str, ' ', str_len);
		get_type(entry->stat->st_mode, &str);
		get_mode(entry->stat->st_mode, &str);
		str += ft_count_digits(get_max_links_count(head)) + 1;
		ft_write_nbr_r2l(entry->stat->st_nlink, str);
		write_to_buf(&str, getpwuid(entry->stat->st_uid)->pw_name, 2, get_longest_username(head));
		write_to_buf(&str, getgrgid(entry->stat->st_gid)->gr_name, 2, get_longest_groupname(head));
		str += ft_count_digits(get_max_bytes_count(head)) + 1;
		ft_write_nbr_r2l(entry->stat->st_size, str);
		str += 2;
		format_time(ctime(&(entry->stat->st_mtime)), str);
		str += 13;
		write_to_buf(&str, entry->name, 0, 0);
		//write_to_buf(&str, "\0", 0, 0);
		ft_putstr(orig_str);
		if(node->next != NULL || single)
		 	ft_putstr("\n");
		free(orig_str);
		if(single)
			break;
		node = node->next;
	}
}

int main(int argc, char **argv)
{
	t_list *paths_lst;
	t_options *options;
	t_list	*head;
	int		single_entry;

	paths_lst = NULL;
	if((options = (t_options*)malloc(sizeof(t_options)))== NULL)
		show_error("args", 1);
	init_options(options);
	get_args(argc, argv, options, &paths_lst);
	if(paths_lst == NULL)
		load_entry(".", &paths_lst, NULL);
	single_entry = (paths_lst->next == NULL);
	paths_lst = parse_user_args(&paths_lst, options);
	if (paths_lst != NULL)
	{
		sort_entries(&paths_lst, options, 1);
		head = paths_lst;
		while(paths_lst != NULL)
		{
			options_ls(((t_entry*)paths_lst->content)->name, options, single_entry);
			if(paths_lst->next != NULL)
				ft_putstr("\n");
			paths_lst = paths_lst->next;
		}
		free_entries_lst(&head);
	}
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
