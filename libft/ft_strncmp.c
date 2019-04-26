/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:51:35 by lpersin           #+#    #+#             */
/*   Updated: 2018/06/22 13:51:36 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 == *s2 && n--)
	{
		if (*s1 == '\0')
			return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
		if (n)
		{
			s1++;
			s2++;
		}
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
