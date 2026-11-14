#include "push_swap.h"
static void zeros_ops(t_bench *bench)
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
static void merge(t_nums **head_a, t_nums **head_b, int algo, int bench_op, t_bench *bench)
{
  if (algo == 1)
    simple(head_a, head_b, bench);
  else if (algo == 2)
    medium(head_a, head_b, bench);
  else if (algo == 3)
    complex(head_a, head_b, bench);
  if (bench_op == 1)
    ft_bench(bench, algo);
}
static void	push_swap(int ac, char **av, t_bench *bench)
{
	t_nums	*head_a;
	t_nums	*head_b;
	int		bench_op;
	int		algo;


	bench_op = 0;
	algo = 0;
	head_b = NULL;
	head_a = fill_lst(ac, av);
	algo = choose(ac, av, &bench_op);
  if (algo == 4)
    adaptive(&head_a, &head_b, bench, ac, av);
  merge(&head_a, &head_b, algo, bench_op, bench);
  free_lst(&head_a);
  free_lst(&head_b);
}

int	main(int ac, char **av)
{
  t_bench bench;
  
  bench.disorder = compute_disorder(ac, av);
  zeros_ops(&bench);
	push_swap(ac, av, &bench);
}
