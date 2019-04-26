/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 12:16:59 by lpersin           #+#    #+#             */
/*   Updated: 2018/07/02 15:43:19 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*p_res;
	const char	*init_needle;
	size_t		s_len;

	if (*needle == '\0')
		return ((char*)haystack);
	init_needle = needle;
	while (*haystack != '\0' && len)
	{
		s_len = len;
		p_res = haystack;
		while (s_len-- && (*p_res++ == *needle++))
		{
			if (*needle == '\0')
				return ((char*)haystack);
		}
		needle = init_needle;
		haystack++;
		len--;
	}
	return (NULL);
}
