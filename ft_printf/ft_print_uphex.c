/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uphex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 19:11:48 by ebajja            #+#    #+#             */
/*   Updated: 2026/10/23 19:18:44 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	rev(unsigned int x, int *i)
{
	if (x >= 16)
		rev(x / 16, i);
	*i += ft_print_char("0123456789ABCDEF"[x % 16]);
}

int	ft_print_uphex(unsigned int num)
{
	int	i;

	i = 0;
	rev(num, &i);
	return (i);
}
