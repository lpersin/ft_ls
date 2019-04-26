#include "ft_ls.h"

int usage_error(char option)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(option);
	ft_putchar('\n');
	ft_putstr("usage: ls [-lRart] [file ...]\n");
	return (1);
}
