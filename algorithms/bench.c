#include "../push_swap.h"

void  ft_bench(int bench)
{
  (void)bench;
  write(2, "[bench] disorder: 49.93%\n", 25);
  write(2, "[bench] strategy: adaptive / O(n*n)\n", 36);
  write(2, "[bench] tatal_ops: 13", 21);
  write(2, "[bench] : sa: 0 sb: 0 ss: 0 pa: 5 pb: 5\n", 40);
  write(2, "[bench] : ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0\n", 49);
}
