/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:29:24 by ebajja            #+#    #+#             */
/*   Updated: 2026/10/23 19:23:50 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	rev(int x, int *i)
{
	if (x >= 10)
		rev(x / 10, i);
	*i += ft_print_char(x % 10 + '0');
}

int	ft_print_num(int num)
{
	int	index;

	index = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
	{
		index += ft_print_char('-');
		num = -num;
	}
	rev(num, &index);
	return (index);
}
