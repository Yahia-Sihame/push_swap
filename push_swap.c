#include "push_swap.h"

void	push_swap(int ac, char **av)
{
	t_nums	*head_a;
	t_nums	*head_b;
	int		bensh;
	int		algo;

	bensh = 0;
	algo = 0;
	head_b = NULL;
	head_a = fill_lst(ac, av);
	algo = choose(ac, av, &bensh);
	if (algo == 1)
		simple(&head_a, &head_b);
}

int	main(int ac, char **av)
{
	push_swap(ac, av);
}
