#include "../push_swap.h"

void	ft_lstclear(t_nums **lst)
{
	t_nums	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
