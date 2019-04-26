/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:56:13 by lpersin           #+#    #+#             */
/*   Updated: 2018/06/22 13:53:10 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	int		len;

	len = ft_strlen(s);
	c = (c & 0xFF);
	chr = (char)c;
	while (len >= 0)
	{
		if (s[len] == chr)
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}
