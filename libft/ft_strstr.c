/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 12:00:11 by lpersin           #+#    #+#             */
/*   Updated: 2018/07/02 15:07:27 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *p_res;
	const char *init_needle;

	if (*needle == '\0')
		return ((char*)haystack);
	init_needle = needle;
	while (*haystack != '\0')
	{
		p_res = haystack;
		while (*p_res++ == *needle++)
			if (*needle == '\0')
				return ((char *)haystack);
		needle = init_needle;
		haystack++;
	}
	return (NULL);
}
