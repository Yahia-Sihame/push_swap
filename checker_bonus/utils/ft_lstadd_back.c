/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:14:41 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 16:39:55 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lstadd_back(t_nums **lst, t_nums *new)
{
	t_nums	*head;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	while (head->next)
		head = head->next;
	head->next = new;
	new->prev = head;
}
