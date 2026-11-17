/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:04:23 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 16:29:22 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_pos(t_nums *head_a)
{
	int	i;
	int	pos;
	int	min;

	i = 0;
	pos = 0;
	min = head_a->num;
	while (head_a)
	{
		if (head_a->num < min)
		{
			min = head_a->num;
			pos = i;
		}
		head_a = head_a->next;
		i++;
	}
	return (pos);
}

static void	push_min_b(t_nums **head_a, t_nums **head_b, t_bench *bench)
{
	int	size;
	int	pos;

	size = ft_lstsize(*head_a);
	pos = get_min_pos(*head_a);
	while (pos > 0 && pos <= size / 2)
	{
		rotate_a(head_a, bench);
		pos--;
	}
	while (pos > size / 2 && pos < size)
	{
		reverse_rotate_a(head_a, bench);
		pos++;
	}
	push_b(head_a, head_b, bench);
}

void	simple(t_nums **head_a, t_nums **head_b, t_bench *bench)
{
	if (!head_a || !*head_a || is_sorted(*head_a))
		return ;
	if (ft_lstsize(*head_a) == 2)
	{
		if ((*head_a)->num > (*head_a)->next->num)
			swap_a(head_a, bench);
		return ;
	}
	while (*head_a)
		push_min_b(head_a, head_b, bench);
	while (*head_b)
		push_a(head_a, head_b, bench);
}
