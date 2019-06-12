/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:37:40 by lpersin           #+#    #+#             */
/*   Updated: 2019/06/11 15:52:55 by lpersin          ###   ########.fr       */
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
# include <errno.h>

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

typedef struct s_entry
{
	char *name;
	struct stat *stat_buf;
}				t_entry;
void		get_args(int ac, char **argv, t_options* const options, t_list** paths_lst);
void		load_options(char *str, t_options * const options);
void	load_entry(char *path, t_list** paths_lst);
void	usage_error(char option);
void	format_time(char *str_date, char *buf);
void	get_mode(mode_t m, char *buf);
void	get_type(mode_t m ,char *buf);
void	read_dir(char *path, t_list **paths_lst);
void	print_paths_lst(t_list *paths_lst);
int		alpha_sort(t_list* a, t_list* b);
int		last_modif_time_sort(t_list* a, t_list*b);
t_entry	*get_t_entry(char *path);
void	show_error(char *path, int die);
int		is_dot_entry(t_list *node);
void	free_entry(void *v_entry, size_t content_size);
void	sort_entries(t_list **entries_lst, t_options* const options, char user_path);
void	free_entries_lst(t_list **entries_lst);
#endif
