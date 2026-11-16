/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:14:21 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 16:39:53 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	if (count != 0 && size > (size_t)-1 / count)
		return (NULL);
	r = malloc(count * size);
	if (!r)
		return (NULL);
	ft_bzero(r, size * count);
	return (r);
}
