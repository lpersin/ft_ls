/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 14:02:24 by lpersin           #+#    #+#             */
/*   Updated: 2018/12/03 16:44:41 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	array_len(int n)
{
	unsigned int len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(int n)
{
	unsigned int	is_neg;
	char			*str;
	unsigned int	len;
	unsigned int	digit;

	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	len = array_len(n) + is_neg;
	str = ft_strnew(len);
	if (str)
	{
		if (is_neg)
			str[0] = '-';
		while (len > is_neg)
		{
			digit = ft_abs(n % 10);
			str[len - 1] = '0' + digit;
			n /= 10;
			len--;
		}
	}
	return (str);
}
