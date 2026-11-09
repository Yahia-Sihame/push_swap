/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 17:58:32 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/08 18:00:55 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_nums **head)
{
	t_nums	*first;
	t_nums	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	last = first;
	while (last->next)
		last = last->next;
	*head = first->next;
	(*head)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	rotate_a(t_nums **head_a)
{
	rotate(head_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_nums **head_b)
{
	rotate(head_b);
	write(1, "rb\n", 3);
}

void	rr(t_nums **head_a, t_nums **head_b)
{
	rotate(head_a);
	rotate(head_b);
	write(1, "rr\n", 3);
}
