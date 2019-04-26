#include "ft_ls.h"

void	format_time(char *str_date, char *buf) //buf size should be 12 + 1
{
	int i;

	i = 0;
	if (str_date)
	{
		str_date += 4;
		while (i < 12)
		{
			buf[i] = *str_date;
			i++;
			str_date++;
		}
	}
}

void	get_mode(mode_t m, char *buf)
{
	char*	chars;
	size_t 	i;

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

void	get_type(mode_t m, char *buf)
{
	if ((m & S_IFMT) == S_IFREG)
		buf[0] = '-';
	else if ((m & S_IFMT) == S_IFDIR)
		buf[0] = 'd';
	else if ((m & S_IFMT) == S_IFCHR)
		buf[0] = 'c';
	else if ((m & S_IFMT) == S_IFBLK)
		buf[0] = 'b';
	else if ((m & S_IFMT) == S_IFIFO)
		buf[0] = 'p';
	else if ((m & S_IFMT) == S_IFLNK)
		buf[0] = 'l';
	else if ((m & S_IFMT) == S_IFSOCK)
		buf[0] = 's';
	else
		buf[0] = 'X';
}
