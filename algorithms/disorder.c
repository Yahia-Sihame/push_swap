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

int	compute_disorder(int ac, char **av)
{
	int	mistakes;
	int	**ints;
	int	count;
	int	i;
	int	j;

	ints = parsed(ac, av);
	count = count_ints(ints);
	mistakes = 0;
	i = 0;
	if (count < 2)
		return (0);
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
	return (mistakes * 100 / (count * (count - 1) / 2));
}
