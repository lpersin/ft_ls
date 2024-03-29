/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:41:23 by lpersin           #+#    #+#             */
/*   Updated: 2019/06/21 16:17:39 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	format_time(char *str_date, char *buf)
{
	if (str_date)
	{
		buf[0] = str_date[4];
		buf[1] = str_date[5];
		buf[2] = str_date[6];
		buf[4] = str_date[8];
		buf[5] = str_date[9];
		if (str_date[23] == '9')
		{
			buf[7] = str_date[11];
			buf[8] = str_date[12];
			buf[9] = str_date[13];
			buf[10] = str_date[14];
			buf[11] = str_date[15];
		}
		else
		{
			buf[8] = str_date[20];
			buf[9] = str_date[21];
			buf[10] = str_date[22];
			buf[11] = str_date[23];
		}
	}
}

void	get_mode(mode_t m, char **buf)
{
	char	*chars;
	size_t	i;

	i = 0;
	chars = "rwxrwxrwx";
	while (i < 9)
	{
		*(*(buf) + i) = (m & (1 << (8 - i))) ? chars[i] : '-';
		i++;
	}
	if (m & S_ISVTX)
		*(*(buf) + 8) = (m & S_IXOTH) ? 't' : 'T';
	if (m & S_ISGID)
		*(*(buf) + 5) = (m & S_IXGRP) ? 's' : 'S';
	if (m & S_ISUID)
		*(*(buf) + 2) = (m & S_IXUSR) ? 's' : 'S';
	*buf += 9;
}

void	get_type(mode_t m, char **buf)
{
	if (S_ISREG(m))
		**buf = '-';
	else if (S_ISDIR(m))
		**buf = 'd';
	else if (S_ISCHR(m))
		**buf = 'c';
	else if (S_ISBLK(m))
		**buf = 'b';
	else if (S_ISFIFO(m))
		**buf = 'p';
	else if (S_ISLNK(m))
		**buf = 'l';
	else if (S_ISSOCK(m))
		**buf = 's';
	else
		**buf = 'X';
	*buf += 1;
}

int		is_dir(t_list *node)
{
	return (S_ISDIR(((t_entry*)node->content)->stat->st_mode));
}

int		is_dot_dir(t_list *node)
{
	return (!ft_strcmp(((t_entry*)node->content)->name, "..")
			|| !ft_strcmp(((t_entry*)node->content)->name, "."));
}
