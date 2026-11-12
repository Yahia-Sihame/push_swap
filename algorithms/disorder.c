/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:42:11 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/11 16:42:19 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_ints(int **ints)
{
	int	i;

	i = 0;
	while (ints[i])
		i++;
	return (i);
}

static long	count_inversions(int **ints, int count)
{
	long	mistakes;
	int		i;
	int		j;

	mistakes = 0;
	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (*ints[i] > *ints[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes);
}

double	compute_disorder(int ac, char **av)
{
	int		**ints;
	int		count;
	long	mistakes;
	long	total;

	ints = parsed(ac, av);
	count = count_ints(ints);
	if (count < 2)
	{
		free_ints(ints);
		return (0.0);
	}
	mistakes = count_inversions(ints, count);
	total = (long)count * (count - 1) / 2;
	free_ints(ints);
	return ((double)mistakes * 100.0 / (double)total);
}
