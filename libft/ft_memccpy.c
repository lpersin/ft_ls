/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:23:37 by lpersin           #+#    #+#             */
/*   Updated: 2018/06/22 13:40:18 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_byte;
	const unsigned char	*src_byte;

	c = (c & 0xFF);
	dst_byte = (unsigned char *)dst;
	src_byte = (const unsigned char *)src;
	while (n--)
	{
		if ((unsigned char)c == *src_byte)
		{
			*dst_byte++ = (unsigned char)c;
			return (dst_byte);
		}
		*dst_byte++ = *src_byte++;
	}
	return (NULL);
}
