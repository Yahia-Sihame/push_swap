/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:58:19 by ebajja            #+#    #+#             */
/*   Updated: 2026/10/24 14:58:20 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	rev(unsigned long x, int *i)
{
	if (x >= 16)
		rev(x / 16, i);
	*i += ft_print_char("0123456789abcdef"[x % 16]);
}

int	ft_print_add(void *p)
{
	int	count;

	if (!p)
		return (write (2, "(nil)", 5));
	count = write (2, "0x", 2);
	rev((unsigned long)p, &count);
	return (count);
}
