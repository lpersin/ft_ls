/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:25:22 by lpersin           #+#    #+#             */
/*   Updated: 2018/06/22 13:41:21 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *src;

	src = (const unsigned char*)s;
	c = (c & 0xFF);
	while (n--)
	{
		if (*src == (unsigned char)c)
			return ((void*)src);
		src++;
	}
	return (NULL);
}
