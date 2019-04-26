/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:36:44 by lpersin           #+#    #+#             */
/*   Updated: 2018/07/04 16:51:51 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_bubblesort(int *tab, size_t size)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
