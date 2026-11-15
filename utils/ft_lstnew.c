/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 01:55:03 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/07 14:40:41 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_nums	*ft_lstnew(int num)
{
	t_nums	*new;

	new = malloc(sizeof(t_nums));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
