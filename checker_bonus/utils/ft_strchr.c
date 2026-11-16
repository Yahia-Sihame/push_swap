/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:18:46 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 16:40:10 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
