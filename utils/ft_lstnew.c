/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:47:23 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 16:47:35 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
