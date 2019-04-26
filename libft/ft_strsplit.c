/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:55:51 by lpersin           #+#    #+#             */
/*   Updated: 2018/12/12 13:15:38 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		get_len_word(char const *s, unsigned int start, char c)
{
	unsigned int len;

	len = 0;
	while (s[start] != c && s[start] != '\0')
	{
		len++;
		start++;
	}
	return (len);
}

static void				pass_char(char const *s, char c, unsigned int *start)
{
	while (s[*start] == c)
		*start += 1;
}

char					**ft_strsplit(char const *s, char c)
{
	char			**word_tab;
	char			*str;
	unsigned int	idx;
	unsigned int	start;
	unsigned int	len;

	if (!s)
		return (NULL);
	start = 0;
	idx = 0;
	word_tab = (char**)malloc((sizeof(*word_tab) * ft_countwords(s, c)) + 1);
	if (word_tab)
	{
		pass_char(s, c, &start);
		while (s[start] != '\0')
		{
			len = get_len_word(s, start, c);
			str = ft_strsub(s, start, len);
			word_tab[idx++] = str;
			start += len;
			pass_char(s, c, &start);
		}
		word_tab[idx] = NULL;
	}
	return (word_tab);
}
