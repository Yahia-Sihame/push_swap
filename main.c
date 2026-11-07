#include "push_swap.h"

int main(int ac, char **av)
{
	t_nums  *head1 = fill_lst(ac, av);
	int	bensh = 0;
	int	algo = choose(ac, av, &bensh);
	t_nums *tmp = head1;
	while (tmp)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
	swap_a(&head1);
	swap_b(&head1);
	swap_a_swap_b(&head1);
	free_lst(&head1);

	printf("---->algo %d\n---->bensh %d\n", algo, bensh);
	return 0;
}
