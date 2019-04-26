/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:53:52 by lpersin           #+#    #+#             */
/*   Updated: 2018/06/29 14:12:52 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	unsigned int	len;
	unsigned int	start;
	char			*t_str;

	if (!s)
		return (NULL);
	if (!*s)
		return (ft_strnew(0));
	start = 0;
	len = ft_strlen(s);
	while (is_space(s[start]))
		start++;
	while (len > 0 && is_space(s[len - 1]))
		len--;
	if (start >= len)
		return (ft_strnew(0));
	t_str = ft_strsub(s, start, (len - start));
	return (t_str);
}
