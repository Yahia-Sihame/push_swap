/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:02:15 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 16:29:42 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

static void	printf_algo(int algo)
{
	if (algo == 1)
		putstr_fd("[bench] strategy: simple / O(n^2)\n", 2);
	else if (algo == 2)
		putstr_fd("[bench] strategy: medium / O(n * sqrt(n))\n", 2);
	else if (algo == 3)
		putstr_fd("[bench] strategy: complex / O(n log n)\n", 2);
	else if (algo == 4)
		putstr_fd("[bench] strategy: adaptive / ...\n", 2);
}

static void	print_ops(t_bench *bench)
{
	putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	putstr_fd(" sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	putstr_fd(" ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	putstr_fd(" pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	putstr_fd(" pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	putstr_fd(" rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	putstr_fd(" rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	putstr_fd("\n", 2);
}

void	ft_bench(t_bench *bench, int algo)
{
	int	total_ops;

	total_ops = bench->sa + bench->sb + bench->ss + bench->pa
		+ bench->pb + bench->ra + bench->rb + bench->rr + bench->rra
		+ bench->rrb + bench->rrr;
	putstr_fd("[bench] disorder: ", 2);
	ft_putdouble(bench->disorder);
	write(2, "%\n", 2);
	printf_algo(algo);
	putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops, 2);
	write(2, "\n", 1);
	print_ops(bench);
}
