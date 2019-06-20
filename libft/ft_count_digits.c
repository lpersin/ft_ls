#include "libft.h"

int ft_count_digits(size_t nb)
{
    int res;
    
    res = 1;

    while(nb / 10 > 0)
    {
        nb = nb / 10;
        res++;
    }
    return res;
}