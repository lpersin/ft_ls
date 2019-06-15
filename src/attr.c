/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:41:23 by lpersin           #+#    #+#             */
/*   Updated: 2019/04/29 13:41:25 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	format_time(char *str_date, char *buf) //buf size should be 12 + 1
{
	int i;

	i = 0;
	if (str_date)
	{
		str_date += 4;
		while (i < 12)
		{
			buf[i] = *str_date;
			i++;
			str_date++;
		}
	}
}

void	get_mode(mode_t m, char *buf)
{
	char*	chars;
	size_t 	i;

	i = 0;
	chars = "rwxrwxrwx";
	while (i < 9)
	{
		buf[i] = (m & (1 << (8 - i))) ? chars[i] : '-';
		i++;
	}
	if (m & S_ISVTX)
		buf[8] = (m & S_IXOTH) ? 't' : 'T';
	if (m & S_ISGID)
		buf[5] = (m & S_IXGRP) ? 's' : 'S';
	if (m & S_ISUID)
		buf[2] = (m & S_IXUSR) ? 's' : 'S';
}

void	get_type(mode_t m, char *buf)
{
	if (S_ISREG(m))
		buf[0] = '-';
	else if (S_ISDIR(m))
		buf[0] = 'd';
	else if (S_ISCHR(m))
		buf[0] = 'c';
	else if (S_ISBLK(m))
		buf[0] = 'b';
	else if (S_ISFIFO(m))
		buf[0] = 'p';
	else if (S_ISLNK(m))
		buf[0] = 'l';
	else if (S_ISSOCK(m))
		buf[0] = 's';
	else
		buf[0] = 'X';
}

int is_dir(t_list *node)
{
	return (S_ISDIR(((t_entry*)node->content)->stat->st_mode));
}

int is_dot_dir(t_list *node)
{
	return (!ft_strcmp(((t_entry*)node->content)->name, "..") ||  !ft_strcmp(((t_entry*)node->content)->name, "."));
}

