/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:02:33 by lpersin           #+#    #+#             */
/*   Updated: 2019/06/21 16:14:58 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	usage_error(char option)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(option);
	ft_putchar('\n');
	ft_putstr("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] ");
	ft_putstr("[file ...]\n");
	exit(1);
}

void	show_error(char *path, int die)
{
	ft_putstr("ls: ");
	perror(path);
	if (die)
		exit(die);
}
