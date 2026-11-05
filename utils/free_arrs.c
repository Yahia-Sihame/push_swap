/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 03:36:42 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/05 15:04:24 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_ints(int **arr, int end)
{
	int	i;
	
	i = 0;
	while (i < end)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_strs(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
