/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:14:59 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/04 23:45:41 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strchr(const char *str, int c)
{
	size_t			i;
	unsigned char	ch;

	if (!str)
		return (NULL);
	ch = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == ch)
			return ((char *)(str + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(str + i));
	return (NULL);
}
