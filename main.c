#include "push_swap.h"

int main(int ac, char **av)
{
	t_nums  *head1 = fill_lst(ac, av);
	t_nums *head = head1;

	while (head)
	{
		printf("%d\n", head->num);
		head = head->next;
	}
	free_lst(&head1);
	return 0;
}
