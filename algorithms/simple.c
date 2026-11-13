#include "../push_swap.h"

static int	get_min_pos(t_nums *head_a)
{
	int	i;
	int	pos;
	int	min;

	i = 0;
	pos = 0;
	min = head_a->num;
	while (head_a)
	{
		if (head_a->num < min)
		{
			min = head_a->num;
			pos = i;
		}
		head_a = head_a->next;
		i++;
	}
	return (pos);
}

void	simple(t_nums **head_a, t_nums **head_b)
{
	int	size;
	int	pos;

	while (*head_a)
	{
		size = ft_lstsize(*head_a);
		pos = get_min_pos(*head_a);
		while (pos > 0 && pos <= size / 2)
		{
			rotate_a(head_a);
			pos--;
		}
		while (pos > size / 2 && pos < size)
		{
			reverse_rotate_a(head_a);
			pos++;
		}
		push_b(head_a, head_b);
	}
	while (*head_b)
		push_a(head_a, head_b);
	free_lst(head_a);
	free_lst(head_b);
}
