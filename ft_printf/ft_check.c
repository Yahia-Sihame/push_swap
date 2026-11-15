/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 14:37:53 by ebajja            #+#    #+#             */
/*   Updated: 2026/10/24 14:38:11 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_args(va_list *args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_print_char(va_arg(*args, int));
	else if (c == 's')
		count += ft_print_str(va_arg(*args, char *));
	else if (c == 'p')
		count += ft_print_add(va_arg(*args, void *));
	else if (c == 'd' || c == 'i')
		count += ft_print_num(va_arg(*args, int));
	else if (c == 'x')
		count += ft_print_lowhex(va_arg(*args, unsigned int));
	else if (c == 'X')
		count += ft_print_uphex(va_arg(*args, unsigned int));
	else if (c == 'u')
		count += ft_print_uint(va_arg(*args, unsigned int));
	else if (c == '%')
		count += ft_print_char('%');
	return (count);
}
