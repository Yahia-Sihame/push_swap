/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 15:08:17 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/08 18:03:57 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_nums **head)
{
	t_nums	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *head;
	(*head)->prev = last;
	*head = last;
}

void	reverse_rotate_a(t_nums **head_a)
{
	reverse_rotate(head_a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_nums **head_b)
{
	reverse_rotate(head_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_nums **head_a, t_nums **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
	write(1, "rrr\n", 4);
}
