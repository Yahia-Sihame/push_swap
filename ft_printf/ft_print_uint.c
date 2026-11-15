/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 19:14:14 by ebajja            #+#    #+#             */
/*   Updated: 2026/10/23 19:14:38 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	rev(unsigned int x, int *i)
{
	if (x >= 10)
		rev(x / 10, i);
	*i += ft_print_char(x % 10 + '0');
}

int	ft_print_uint(unsigned int num)
{
	int	i;

	i = 0;
	rev(num, &i);
	return (i);
}
