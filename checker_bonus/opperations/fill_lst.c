/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 15:08:17 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 16:38:01 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_lst(t_nums **head)
{
	t_nums	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

t_nums	*fill_lst(int ac, char **av)
{
	int		**nums;
	int		i;
	t_nums	*head;
	t_nums	*tmp;

	nums = parsed(ac, av);
	head = NULL;
	i = 0;
	while (nums[i])
	{
		tmp = ft_lstnew(*nums[i]);
		free(nums[i]);
		ft_lstadd_back(&head, tmp);
		i++;
	}
	free(nums[i]);
	free(nums);
	return (head);
}
