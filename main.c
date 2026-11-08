/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 15:38:28 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/08 16:16:43 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_nums  *head1 = fill_lst(ac, av);
	
	t_nums *tmp = head1;
	swap_a(&tmp);
	while (tmp)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
	free_lst(&head1);

	return 0;
}
