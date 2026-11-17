/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:51:15 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 17:18:30 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	zeros_ops(t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

static void	merge(t_nums **head_a, t_nums **head_b, int algo, t_bench *bench)
{
	if (algo == 1)
		simple(head_a, head_b, bench);
	else if (algo == 2)
		medium(head_a, head_b, bench);
	else if (algo == 3)
		complex(head_a, head_b, bench);
}

static void	push_swap(int ac, char **av, t_bench *bench)
{
	t_nums	*head_a;
	t_nums	*head_b;
	int		bench_op;
	int		algo;
	double	disorder;

	disorder = compute_disorder(ac, av);
	bench_op = 0;
	head_b = NULL;
	head_a = fill_lst(ac, av);
	algo = choose(ac, av, &bench_op);
	if (!head_a || is_sorted(head_a))
	{
		if (bench_op == 1)
			ft_bench(bench, algo);
		free_lst(&head_a);
		return ;
	}
	if (algo == 4)
		adaptive(&head_a, &head_b, bench, disorder);
	merge(&head_a, &head_b, algo, bench);
	if (bench_op == 1)
		ft_bench(bench, algo);
	free_lst(&head_a);
	free_lst(&head_b);
}

int	main(int ac, char **av)
{
	t_bench	bench;

	if (ac < 2)
		return (0);
	bench.disorder = compute_disorder(ac, av);
	zeros_ops(&bench);
	push_swap(ac, av, &bench);
	return (0);
}
