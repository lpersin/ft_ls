/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:49:47 by lpersin           #+#    #+#             */
/*   Updated: 2018/06/22 14:03:43 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	len;
	unsigned int	i;
	char			*m_str;

	if (!s || !(*f))
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	m_str = ft_strnew(len);
	if (m_str)
	{
		while (s[i] != '\0')
		{
			m_str[i] = (*f)(s[i]);
			i++;
		}
	}
	return (m_str);
}
