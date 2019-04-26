/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:14:43 by lpersin           #+#    #+#             */
/*   Updated: 2018/09/20 15:16:05 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include "libft.h"

#define BUFF_SIZE 32

int		get_next_line(const int fd, char **line);

#	endif
