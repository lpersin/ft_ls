/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:23:09 by lpersin           #+#    #+#             */
/*   Updated: 2018/06/29 15:00:19 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*dst_byte;
	const unsigned char		*src_byte;

	dst_byte = (unsigned char*)dst;
	src_byte = (const unsigned char *)src;
	if (dst > src)
	{
		while (len)
		{
			dst_byte[len - 1] = src_byte[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
