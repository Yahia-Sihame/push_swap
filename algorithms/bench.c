#include "push_swap.h"

static void   printf_algo(int algo)
{
    if (algo == 1)
  ft_printf("[bench] strategy: simple / O(n^2)\n");
  else if (algo == 2)
  ft_printf("[bench] strategy: medium / O(n * sqrt(n)\n");
  else if (algo == 3)
  ft_printf("[bench] strategy: complex / O(n log n)\n");
  else if (algo == 4)
    ft_printf("[bench] strategy: adaptive / ...\n");
}
void  ft_bench(t_bench *bench, int algo)
{
  int total_ops;

  total_ops = bench->sa + bench->sb + bench->ss + bench->pa + bench->pb + bench->ra + bench->rb + bench->rr + bench->rra + bench->rrb + bench->rrr;
  ft_printf("[bench] disorder: ");
  ft_putdouble(bench->disorder);
  write(2, "%\n",2);
  printf_algo(algo);
  ft_printf("[bench] total_ops: %d\n",total_ops);
  ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
  ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}
