/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihame <ysihame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 23:26:54 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/09 18:30:56 by ysihame          ###   ########.fr       */
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
	else if (!ft_strcmp(str, BNSH))
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
	while (check_algo(av[i]))
		i++;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (check_algo(av[i]))
				free_exit(NULL, NULL);
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
  if (ac < 2)
    exit(0);
	if (check_args(ac, av))
	{
		write (2, "Error\n", 6);
		exit (1);
	}
}
