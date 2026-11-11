/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 17:03:26 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/08 17:56:59 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_nums **head_a, t_nums **head_b)
{
	t_nums	*node;

	if (!head_a || !head_b || !*head_b)
		return ;
	node = *head_b;
	*head_b = node->next;
	if (*head_b)
		(*head_b)->prev = NULL;
	node->next = *head_a;
	if (*head_a)
		(*head_a)->prev = node;
	node->prev = NULL;
	*head_a = node;
	write(1, "pa\n", 3);
}

void	push_b(t_nums **head_a, t_nums **head_b)
{
	t_nums	*node;

	if (!head_a || !head_b || !*head_a)
		return ;
	node = *head_a;
	*head_a = node->next;
	if (*head_a)
		(*head_a)->prev = NULL;
	node->next = *head_b;
	if (*head_b)
		(*head_b)->prev = node;
	node->prev = NULL;
	*head_b = node;
	write(1, "pb\n", 3);
}
