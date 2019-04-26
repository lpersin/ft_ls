/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:17:49 by lpersin           #+#    #+#             */
/*   Updated: 2018/06/22 13:42:35 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*src_byte;
	char		*dst_byte;

	src_byte = (const char*)src;
	dst_byte = (char*)dst;
	while (n--)
		*dst_byte++ = *src_byte++;
	return (dst);
}
