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
		read_dir(".", &paths_lst, options);
		ft_putstr("BEFORE\n");
		print_paths_lst(paths_lst);
		//paths_lst = ft_lst_del_occurences(paths_lst, is_dot_entry, free_entry);
		ft_putstr("\n\n");
		ft_fct_sortlst(&paths_lst, alpha_sort);

		ft_putstr("AFTER\n");
		print_paths_lst(paths_lst);
}

void options_ls(t_list *paths_lst, t_options* const options)
{
	if (paths_lst == NULL)
		read_dir(".", &paths_lst, options);
	if (options->a == 0)
		paths_lst = ft_lst_del_occurences(paths_lst, is_dot_entry, free_entry);
	if (options->t == 1)
		ft_fct_sortlst(&paths_lst, &last_modif_time_sort);
	if (options->r == 1)
		ft_lstrev(&paths_lst);
}

int main(int argc, char **argv)
{
	t_list *paths_lst;
	t_options *options;

	paths_lst = NULL;
	options = (t_options*)malloc(sizeof(t_options));
	if (argc > 1)
	{
		get_args(argc, argv, options, &paths_lst);
		//get_t_dir();
		//if (options->R == 1)
		//	recursive_ls();
		//else
		//	options_ls(paths_lst, options);
	}
	else
		default_ls(paths_lst, options);
	
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
