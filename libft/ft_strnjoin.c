/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:02:44 by lpersin           #+#    #+#             */
/*   Updated: 2018/09/20 09:48:35 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = ft_strnew(n);
	str[n] = '\0';
	while (n--)
	{
		if (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		else if (s2[j] != '\0')
		{
			str[i + j] = s2[j];
			j++;
		}
	}
	return (str);
}
