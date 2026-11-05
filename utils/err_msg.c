/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 23:26:54 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/05 15:19:13 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


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
	else if (!ft_strcmp(str, BNCH))
		return (1);
	return (0);
}

static int	check_args(int ac, char **av)
{
	int	i;
	int	j;
	
	if (ac < 2)
		return (1);
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (check_algo(av[i]))
				break;
			if (!(av[i][j] >= '0' && av[i][j] <= '9')
				&& av[i][j] != ' ' && av[i][j] != '-' 
				&& av[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	err_msg(int ac, char **av)
{
	if (ac < 2 || check_args(ac, av))
	{
		write (2, "Error\n", 6);
		exit (1);
	}
}
