#include "push_swap.h"

int main(int ac, char **av)
{
	t_nums  *head = fill_lst(ac, av);
	while (head)
	{
		printf("%d\n", head->num);
		head = head->next;
	}
	ft_lstclear(&head);
	return 0;
}
