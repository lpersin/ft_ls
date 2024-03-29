/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:02:59 by lpersin           #+#    #+#             */
/*   Updated: 2019/06/21 16:34:19 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_args(int ac, char **av, t_options *const options,
			t_list **paths_lst)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "--") == 0)
			options->loaded = 1;
		else if (!options->loaded && av[i][0] == '-' && av[i][1] != '\0')
			load_options(av[i] + 1, options);
		else
		{
			options->loaded = 1;
			load_entry(av[i], paths_lst, NULL);
		}
		i++;
	}
}

void	load_options(char *str, t_options *const options)
{
	if (options == NULL)
		show_error("Problem loading args", 1);
	while (*str)
	{
		if (*str == 'l')
			options->l = 1;
		else if (*str == 'R')
			options->rec = 1;
		else if (*str == 'a')
			options->a = 1;
		else if (*str == 'r')
			options->r = 1;
		else if (*str == 't')
			options->t = 1;
		else
			usage_error(*str);
		str++;
	}
}

t_list	*delete_invalid_path(t_list *head)
{
	t_list		*tmp_node;
	int			res;

	tmp_node = NULL;
	if (head == NULL)
		return (NULL);
	res = stat(((t_entry*)head->content)->name,
			((t_entry*)head->content)->stat);
	if (res == -1)
	{
		show_error(((t_entry*)head->content)->name, 0);
		tmp_node = head->next;
		free_entry(head->content, head->content_size);
		free(head);
		head = NULL;
		return (delete_invalid_path(tmp_node));
	}
	head->next = delete_invalid_path(head->next);
	return (head);
}

t_list	*show_user_paths(t_list *head, int *flag, t_options *opt)
{
	t_list	*tmp_node;
	t_entry	*entry;

	if (head == NULL)
		return (NULL);
	entry = (t_entry*)head->content;
	opt->l ? lstat(entry->name, entry->stat) : stat(entry->name, entry->stat);
	if (!is_dir(head))
	{
		*flag = 1;
		if (opt->l)
			l_print(head, 1);
		else
		{
			ft_putstr(((t_entry*)head->content)->name);
			ft_putstr("\n");
		}
		tmp_node = head->next;
		free_entry(head->content, head->content_size);
		free(head);
		head = NULL;
		return (show_user_paths(tmp_node, flag, opt));
	}
	head->next = show_user_paths(head->next, flag, opt);
	return (head);
}

t_list	*parse_user_args(t_list **head, t_options *options)
{
	t_list	*node;
	int		flag;

	flag = 0;
	ft_fct_sortlst(head, alpha_sort);
	node = delete_invalid_path(*head);
	sort_entries(&node, options, 1);
	node = show_user_paths(node, &flag, options);
	if (node != NULL && flag)
		ft_putstr("\n");
	return (node);
}
