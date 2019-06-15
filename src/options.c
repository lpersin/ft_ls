/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:02:59 by lpersin           #+#    #+#             */
/*   Updated: 2019/06/13 17:03:05 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void get_args(int ac, char **av, t_options* const options, t_list** paths_lst)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "--") == 0)
			options->loaded = 1;
		else if (!options->loaded && av[i][0] == '-' && av[i][1] != '\0'){
			load_options(av[i] + 1, options);}
		else
		{
			options->loaded = 1;
			load_entry(av[i], paths_lst, NULL);
		}
		i++;
	}
}

void load_options(char *str, t_options* const options)
{
	if (options == NULL)
		show_error("Problem loading args", 1);
	while (*str)
	{
		if (*str == 'l')
			options->l = 1;
		else if (*str == 'R')
			options->R = 1;
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


