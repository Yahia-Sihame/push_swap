/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysihame <ysihame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:21:03 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/17 10:22:46 by ysihame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_sorted(t_nums *lst_a)
{
	while (lst_a && lst_a->next)
	{
		if (lst_a->num > lst_a->next->num)
			return (0);
		lst_a = lst_a->next;
	}
	return (1);
}

static int	execute(t_nums **lst_a, t_nums **lst_b, char *op)
{
	if (!ft_strcmp(op, "sa"))
		swap_a(lst_a);
	else if (!ft_strcmp(op, "sb"))
		swap_b(lst_b);
	else if (!ft_strcmp(op, "ss"))
		ss(lst_a, lst_b);
	else if (!ft_strcmp(op, "pa"))
		push_a(lst_a, lst_b);
	else if (!ft_strcmp(op, "pb"))
		push_b(lst_b, lst_a);
	else if (!ft_strcmp(op, "ra"))
		rotate_a(lst_a);
	else if (!ft_strcmp(op, "rb"))
		rotate_b(lst_b);
	else if (!ft_strcmp(op, "rr"))
		rr(lst_a, lst_b);
	else if (!ft_strcmp(op, "rra"))
		reverse_rotate_a(lst_a);
	else if (!ft_strcmp(op, "rrb"))
		reverse_rotate_b(lst_b);
	else if (!ft_strcmp(op, "rrr"))
		rrr(lst_a, lst_b);
	else
		return (1);
	return (0);
}

static int	end_line(t_nums **lst_a, t_nums **lst_b, char *op, int *i)
{
	op[*i] = '\0';
	if (*i == 0 || execute(lst_a, lst_b, op))
		return (1);
	*i = 0;
	return (0);
}

static int	read_instruction(t_nums **lst_a, t_nums **lst_b)
{
	char	op[4];
	char	c;
	int		i;
	ssize_t	bytes;

	i = 0;
	bytes = read(0, &c, 1);
	while (bytes > 0)
	{
		if (c == '\n' && end_line(lst_a, lst_b, op, &i))
			return (1);
		else if (c != '\n' && c != '\r')
		{
			if (i >= 3)
				return (1);
			op[i++] = c;
		}
		bytes = read(0, &c, 1);
	}
	if (bytes < 0)
		return (1);
	op[i] = '\0';
	if (i > 0 && execute(lst_a, lst_b, op))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_nums	*lst_a;
	t_nums	*lst_b;

	if (ac < 2)
		return (0);
	lst_a = fill_lst(ac, av);
	lst_b = NULL;
	if (!lst_a)
		return (write(2, "Error\n", 6), 1);
	if (read_instruction(&lst_a, &lst_b))
	{
		free_lst(&lst_a);
		free_lst(&lst_b);
		return (write(2, "Error\n", 6), 1);
	}
	if (is_sorted(lst_a) && !lst_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_lst(&lst_a);
	free_lst(&lst_b);
	return (0);
}
