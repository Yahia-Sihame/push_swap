#include "push_swap.h"
static void merge(t_nums **head_a, t_nums **head_b, int algo, int bench)
{
  if (algo == 1)
    simple(head_a, head_b);
  else if (algo == 2)
    medium(head_a, head_b);
  else if (algo == 3)
    complex(head_a, head_b);
  else if (algo == 4)
    adaptive(head_a, head_b);
  if (bench == 1)
    ft_bench(bench);
}
static void	push_swap(int ac, char **av)
{
	t_nums	*head_a;
	t_nums	*head_b;
	int		bench;
	int		algo;

	bench = 0;
	algo = 0;
	head_b = NULL;
	head_a = fill_lst(ac, av);
	algo = choose(ac, av, &bench);
  merge(&head_a, &head_b, algo, bench);
}

int	main(int ac, char **av)
{
	push_swap(ac, av);
}
