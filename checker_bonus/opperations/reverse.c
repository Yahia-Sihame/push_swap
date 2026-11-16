/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihame <ysihame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 15:08:17 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/10 01:07:05 by ysihame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

void	reverse_rotate_b(t_nums **head_b)
{
	reverse_rotate(head_b);
}

void	rrr(t_nums **head_a, t_nums **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
}
