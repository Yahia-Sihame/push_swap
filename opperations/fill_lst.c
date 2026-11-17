/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:22:59 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 16:44:16 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_index(t_nums *head)
{
	t_nums	*cur;
	t_nums	*other;
	int		rank;

	cur = head;
	while (cur)
	{
		rank = 0;
		other = head;
		while (other)
		{
			if (other->num < cur->num)
				rank++;
			other = other->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}

int	is_sorted(t_nums *head)
{
	while (head && head->next)
	{
		if (head->num > head->next->num)
			return (0);
		head = head->next;
	}
	return (1);
}

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
	assign_index(head);
	return (head);
}
