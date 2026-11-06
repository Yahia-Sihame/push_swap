#include "../push_swap.h"

void	free_lst(t_nums **head)
{
	t_nums	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

t_nums	*fill_lst(int ac, char **av)
{
	int	**nums;
	int	i;
	t_nums	*head;
	t_nums	*tmp;
	
	nums = parsed(ac, av);
	head = NULL;
	i = 0;
	while (nums[i])
	{
		tmp = ft_lstnew(*nums[i]);
		free(nums[i]);
		ft_lstadd_back(&head, tmp);
		i++;
	}
	free(nums[i]);
	free(nums);
	return (head);
}
