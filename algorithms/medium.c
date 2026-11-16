/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:04:07 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 16:29:31 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static int	get_max_pos(t_nums *head_b)
{
	int	i;
	int	pos;
	int	max;

	i = 0;
	pos = 0;
	max = head_b->num;
	while (head_b)
	{
		if (head_b->num > max)
		{
			max = head_b->num;
			pos = i;
		}
		head_b = head_b->next;
		i++;
	}
	return (pos);
}

static void	push_chunks(t_nums **head_a, t_nums **head_b, int chunk,
		t_bench *bench)
{
	int	i;

	i = 0;
	while (*head_a)
	{
		if ((*head_a)->index <= i)
		{
			push_b(head_a, head_b, bench);
			rotate_b(head_b, bench);
			i++;
		}
		else if ((*head_a)->index <= i + chunk)
		{
			push_b(head_a, head_b, bench);
			i++;
		}
		else
			rotate_a(head_a, bench);
	}
}

static void	push_back(t_nums **head_a, t_nums **head_b, t_bench *bench)
{
	int	pos;
	int	size;

	while (*head_b)
	{
		pos = get_max_pos(*head_b);
		size = ft_lstsize(*head_b);
		if (pos <= size / 2)
			while (pos-- > 0)
				rotate_b(head_b, bench);
		else
			while (pos++ < size)
				reverse_rotate_b(head_b, bench);
		push_a(head_a, head_b, bench);
	}
}

void	medium(t_nums **head_a, t_nums **head_b, t_bench *bench)
{
	int	chunk;

	chunk = ft_sqrt(ft_lstsize(*head_a)) * 14 / 10;
	if (chunk < 1)
		chunk = 1;
	push_chunks(head_a, head_b, chunk, bench);
	push_back(head_a, head_b, bench);
}
