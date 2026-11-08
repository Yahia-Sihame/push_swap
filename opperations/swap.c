/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 14:19:22 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/08 16:11:52 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_nums **head)
{
	t_nums	*first;
	t_nums	*second;

	if (!head || !*head || !(*head)->next)
		return;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;	
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
	write (1, "sa\n", 3);
}

void	swap_b(t_nums **head)
{
	t_nums *tmp = *head;
	(void)tmp;
	write (1, "sb\n", 3);
}

void	swap_a_swap_b(t_nums **head)
{
	t_nums *tmp = *head;
	(void)tmp;
	write (1, "ss\n", 3);
}
