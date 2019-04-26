/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:46:06 by lpersin           #+#    #+#             */
/*   Updated: 2018/06/22 13:46:29 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;
	int		len;

	len = ft_strlen(s);
	c = (c & 0xFF);
	chr = (char)c;
	while (len >= 0)
	{
		if (*s == chr)
			return ((char *)s);
		s++;
		len--;
	}
	return (NULL);
}
