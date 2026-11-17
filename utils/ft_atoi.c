/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:45:52 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 16:46:03 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

long	ft_atoi(const char *str, int **ints, char **arr)
{
	long	num;
	int		sign;
	int		has_digit;

	num = 0;
	has_digit = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = get_sign(&str);
	while (*str >= '0' && *str <= '9')
	{
		has_digit = 1;
		num = num * 10 + (*str - '0');
		if ((sign == 1 && num > MAX) || (sign == -1 && num > (long)MAX + 1))
			free_exit(ints, arr);
		str++;
	}
	if (!has_digit || *str != '\0')
		free_exit(ints, arr);
	return (num * sign);
}
