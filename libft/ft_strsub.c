/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:53:19 by lpersin           #+#    #+#             */
/*   Updated: 2018/06/22 13:53:34 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*strsub;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	strsub = ft_strnew(len);
	if (strsub)
	{
		while (i < len)
		{
			strsub[i] = s[start + i];
			i++;
		}
	}
	return (strsub);
}
