/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 17:58:32 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 16:38:07 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

void	rotate_b(t_nums **head_b)
{
	rotate(head_b);
}

void	rr(t_nums **head_a, t_nums **head_b)
{
	rotate(head_a);
	rotate(head_b);
}
