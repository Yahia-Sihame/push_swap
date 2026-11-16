/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:24:44 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 16:44:26 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_nums **head)
{
	t_nums	*first;
	t_nums	*second;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
}

void	swap_a(t_nums **head_a, t_bench *bench)
{
	swap(head_a);
	bench->sa += 1;
	write(1, "sa\n", 3);
}

void	swap_b(t_nums **head_b, t_bench *bench)
{
	swap(head_b);
	bench->sb += 1;
	write(1, "sb\n", 3);
}

void	ss(t_nums **head_a, t_nums **head_b, t_bench *bench)
{
	swap(head_a);
	swap(head_b);
	bench->ss += 1;
	write(1, "ss\n", 3);
}
