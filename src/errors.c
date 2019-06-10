#include "ft_ls.h"

int usage_error(char option)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(option);
	ft_putchar('\n');
	ft_putstr("usage: ls [-lRart] [file ...]\n");
	return (1);
}

void show_error(char *path)
{
	ft_putstr("ls: ");
	perror(path);
	exit(1);
}
