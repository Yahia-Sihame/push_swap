/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:08:14 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 16:38:28 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(int **ints)
{
	int	x;
	int	y;

	x = 0;
	while (ints[x])
	{
		y = x + 1;
		while (ints[y])
		{
			if (*ints[x] == *ints[y])
				free_exit(ints, NULL);
			y++;
		}
		x++;
	}
}
