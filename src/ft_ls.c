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

int main(int argc, char **argv)
{
	/*
	t_list *paths_lst;
	t_options *options;

	paths_lst = NULL;
	options = (t_options*)malloc(sizeof(t_options));
	get_args(argc, argv, options, &paths_lst);
	
	
	DIR *dir_p = opendir("toto");
	struct dirent* dp;
	dp = readdir(dir_p); 

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
	return(0);
	*/

	
}
