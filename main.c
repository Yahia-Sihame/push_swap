#include "push_swap.h"


int main(int ac, char **av)
{
	int bensh = 0;
	 choose(ac,av,&bensh);
	t_nums *list;
	t_nums *tmp;
	list = fill_lst(ac, av);
	tmp = list;
	while ( tmp )
	{
		printf("%d -> \n",tmp->num);
		tmp = tmp->next;
	}
	free_lst(&list);
	return 0;
}
