/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 12:57:19 by lpersin           #+#    #+#             */
/*   Updated: 2018/07/02 15:45:28 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f'
			|| c == '\r' || c == ' ');
}

int			ft_atoi(const char *nptr)
{
	int result;
	int sign;

	result = 0;
	sign = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = 1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
		result = (10 * result) + (*nptr++ - '0');
	return ((sign) ? -result : result);
}
