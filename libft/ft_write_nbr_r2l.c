#include "libft.h"

void ft_write_nbr_r2l(int n, char *buf)
{
	if (n > 9)
		ft_write_nbr_r2l(n / 10, buf-1);
	*buf = '0' + (n % 10);
}