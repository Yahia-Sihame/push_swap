#include "../push_swap.h"

int	ft_lstsize(t_nums *lst)
{
	int		i;
	t_nums	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
