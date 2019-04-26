/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:01:31 by lpersin           #+#    #+#             */
/*   Updated: 2019/04/24 15:27:40 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


char get_type(mode_t m)
{
	if ((m & S_IFMT) == S_IFREG)
		return ('-');
	else if ((m & S_IFMT) == S_IFDIR)
		return ('d');
	else if ((m & S_IFMT) == S_IFCHR)
		return ('c');
	else if ((m & S_IFMT) == S_IFBLK)
		return ('b');
	else if ((m & S_IFMT) == S_IFIFO)
		return ('p');
	else if ((m & S_IFMT) == S_IFLNK)
		return ('l');
	else if ((m & S_IFMT) == S_IFSOCK)
		return ('s');
	else
		return('X');
}

void str_mode(mode_t m, char *buf)
{
	char* chars;
	size_t i;

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


//www.gnu.org/software/libc/manual/html_node/Testing-File-Type.html
//https://opensource.apple.com/source/xnu/xnu-344/bsd/sys/stat.h.auto.html
//https://pubs.opengroup.org/onlinepubs/007904875/basedefs/sys/stat.h.html
//man stat

int main(int argc, char **argv)
{
	t_list *paths_lst;
	t_options *options;

	paths_lst = NULL;
	options = (t_options*)malloc(sizeof(t_options));
	get_args(argc, argv, options, &paths_lst);

	DIR *dir_p = opendir("toto");
	struct dirent* dp;
	dp = readdir(dir_p); 

	/*while ((dp = readdir(dir_p)) != NULL)
	{
		ft_putstr(dp->d_name);
		ft_putnbr(dp->d_namlen);
		ft_putstr("\n");
	}*/

	char *buf_mode = ft_strnew(9);
	struct stat *buf = (struct stat*)malloc(sizeof(struct stat));
	stat("/home/trokadero/Work/19/ft_ls/test", buf);
	str_mode(buf->st_mode, buf_mode);
	ft_putstr("\nNom: "); ft_putstr(dp->d_name);
	ft_putstr("\nType: "); ft_putchar(get_type(buf->st_mode));
	ft_putstr("\nModes: "); ft_putstr(buf_mode);
	ft_putstr("\nNb liens: ");
	ft_putstr("\nProprietaire: ");
	ft_putstr("\nGroupe: ");
	ft_putstr("\nTaille: ");
	ft_putstr("\nDate de derniere modification: ");
	return(0);
}
