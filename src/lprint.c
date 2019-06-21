/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:37:26 by lpersin           #+#    #+#             */
/*   Updated: 2019/06/21 17:09:32 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_longest_groupname(t_list *node)
{
	int		res;
	int		candidate;
	t_entry	*entry;

	res = 0;
	while (node != NULL)
	{
		entry = (t_entry*)node->content;
		candidate = ft_strlen(getgrgid(entry->stat->st_gid)->gr_name);
		if (candidate > res)
			res = candidate;
		node = node->next;
	}
	return (res);
}

void	write_to_buf(char **buf, char *str, int pre_offset, int post_offset)
{
	int i;

	i = 0;
	*buf += pre_offset;
	while (str && *str)
	{
		**buf = *str;
		*buf += 1;
		str++;
		i++;
	}
	while (post_offset > i)
	{
		**buf = ' ';
		*buf += 1;
		i++;
	}
}

void	lprint_symlimk_handler(t_list *node, char *s)
{
	char	*str;
	ssize_t	offset;
	t_entry	*entry;

	str = NULL;
	if (s)
	{
		str = (char*)malloc(sizeof(char) * PATH_MAX);
		entry = (t_entry*)node->content;
		if ((offset = readlink(entry->full_path, str, PATH_MAX)) == -1)
			return ;
		str[offset] = '\0';
		ft_putstr(" -> ");
		ft_putstr(str);
		free(str);
	}
}

void	l_print(t_list *node, int single)
{
	t_entry *entry;
	char	*str;
	int		str_len;
	t_list	*head;
	char	*orig_str;

	head = node;
	if (node != NULL)
		str_len = l_min_str_size(node) + 2;
	while (node != NULL)
	{
		entry = ((t_entry*)node->content);
		str = ft_strnew(str_len);
		orig_str = str;
		l_print_helper(entry, head, &str, str_len);
		if (S_ISLNK(entry->stat->st_mode))
			lprint_symlimk_handler(node, str);
		if (node->next != NULL || single)
			ft_putstr("\n");
		free(orig_str);
		if (single)
			break ;
		node = node->next;
	}
}

void	l_print_helper(t_entry *entry, t_list *head, char **str, int str_len)
{
	char	*orig_str;
	char	*pw_name;
	
	pw_name = ft_strdup(getpwuid(entry->stat->st_uid)->pw_name);
	ft_strfill(*str, ' ', str_len);
	orig_str = *str;
	get_type(entry->stat->st_mode, str);
	get_mode(entry->stat->st_mode, str);
	*str += ft_count_digits(get_max_links_count(head)) + 1;
	ft_write_nbr_r2l(entry->stat->st_nlink, *str);
	write_to_buf(str, pw_name, 2,
					get_longest_username(head));
	write_to_buf(str, getgrgid(entry->stat->st_gid)->gr_name, 2,
					get_longest_groupname(head));
	*str += ft_count_digits(get_max_bytes_count(head)) + 1;
	ft_write_nbr_r2l(entry->stat->st_size, *str);
	*str += 2;
	format_time(ctime(&(entry->stat->st_mtime)), *str);
	*str += 13;
	**str = '\0';
	ft_putstr(orig_str);
	ft_putstr(entry->name);
	free(pw_name);
}
