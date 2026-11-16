/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:09:02 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 16:55:01 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_algo(char *str)
{
	if (!ft_strcmp(str, SMPL))
		return (1);
	else if (!ft_strcmp(str, MD))
		return (1);
	else if (!ft_strcmp(str, ADPT))
		return (1);
	else if (!ft_strcmp(str, CMPLX))
		return (1);
	else if (!ft_strcmp(str, BNSH))
		return (1);
	return (0);
}

static int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (str[i] == '\0');
}

static int	check_chars(char *str)
{
	int	j;

	j = 0;
	if (is_empty(str))
		free_exit(NULL, NULL);
	while (str[j])
	{
		if (check_algo(str))
			free_exit(NULL, NULL);
		if (!(str[j] >= '0' && str[j] <= '9')
			&& str[j] != ' ' && str[j] != '-'
			&& str[j] != '+')
			return (1);
		j++;
	}
	return (0);
}

static int	check_args(int ac, char **av)
{
	int	i;

	if (ac < 2)
		return (1);
	i = 1;
	while (check_algo(av[i]))
		i++;
	while (i < ac)
	{
		if (check_chars(av[i]))
			return (1);
		i++;
	}
	return (0);
}

void	err_msg(int ac, char **av)
{
	if (ac < 2)
		exit(0);
	if (check_args(ac, av))
	{
		write (2, "Error\n", 6);
		exit (1);
	}
}
