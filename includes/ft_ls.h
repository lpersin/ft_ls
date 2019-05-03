/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:37:40 by lpersin           #+#    #+#             */
/*   Updated: 2019/04/29 13:42:31 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "libft.h"
# include <sys/types.h>
# include <stdio.h>
# include <sys/stat.h>

typedef struct	s_options
{
	unsigned char a:1;
	unsigned char l:1;
	unsigned char r:1;
	unsigned char R:1;
	unsigned char t:1;
	char :2;
	unsigned char loaded:1;
}				t_options;

typedef struct s_dir
{
	char *name;
	struct stat *stat_buf;
}				t_dir;

int 	get_args(int ac, char **argv, t_options* const options, t_list** paths_lst);
int 	load_options(char *str, t_options * const options);
int 	load_path(char *path, int path_len, t_list** paths_lst);
int 	usage_error(char option);
void	format_time(char *str_date, char *buf);
void	get_mode(mode_t m, char *buf);
void	get_type(mode_t m ,char *buf);
void	read_dir(char *path, t_list **paths_lst);
void	print_paths_lst(t_list *paths_lst);
int		alpha_sort(t_list* a, t_list* b);
int		last_modif_time_sort(t_list* a, t_list*b);

#endif
