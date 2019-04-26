/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:10:36 by lpersin           #+#    #+#             */
/*   Updated: 2018/09/26 12:59:32 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static	int		read_line(const int fd, char *buf, char **line,
					char array[FOPEN_MAX][BUFF_SIZE])
{
	char	*offset;
	char	*tmp;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = *line;
		if ((offset = ft_strchr(buf, '\n')) != NULL)
		{
			if ((*line = ft_strnjoin(*line, buf, ft_strlen(*line) +
							(size_t)offset - (size_t)buf)) == NULL)
				return (-1);
			free(tmp);
			ft_strcpy(array[fd], offset + 1);
			return (1);
		}
		else
		{
			if ((*line = ft_strjoin(*line, buf)) == NULL)
				return (-1);
		}
		free(tmp);
	}
	return (ret);
}

static	int		buf_line(int fd, char arr[FOPEN_MAX][BUFF_SIZE],
						char **line, char *buf)
{
	char	*tmp_buf;
	int		res;

	if ((tmp_buf = ft_strchr(arr[fd], '\n')) != NULL)
	{
		*line = ft_strsub(arr[fd], 0, ((size_t)tmp_buf - (size_t)arr[fd]));
		if (!*line)
			return (-1);
		ft_strcpy(arr[fd], tmp_buf + 1);
		return (1);
	}
	else
	{
		*line = ft_strdup(arr[fd]);
		ft_strclr(arr[fd]);
		if (!*line)
			return (-1);
		res = read_line(fd, buf, line, arr);
	}
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	static char array[FOPEN_MAX][BUFF_SIZE];
	char		buf[BUFF_SIZE + 1];
	int			res;

	if (fd < 0 || line == NULL || fd >= FOPEN_MAX)
		return (-1);
	res = buf_line(fd, array, line, buf);
	if (ft_strlen(*line) != 0)
		return (1);
	else if (res == 0)
		return (0);
	else if (res > 0)
		return (1);
	else
		return (-1);
}
