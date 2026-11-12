#include "../push_swap.h"

static int	get_min_pos(t_nums *a)
{
	int	i;
	int	pos;
	int	min;

	i = 0;
	pos = 0;
	min = a->num;
	while (a)
	{
		if (a->num < min)
		{
			min = a->num;
			pos = i;
		}
		a = a->next;
		i++;
	}
	return (pos);
}

void	simple(t_nums **a, t_nums **b)
{
	int	size;
	int	pos;

	while (*a)
	{
		size = ft_lstsize(*a);
		pos = get_min_pos(*a);
		while (pos > 0 && pos <= size / 2)
		{
			rotate_a(a);
			pos--;
		}
		while (pos > size / 2 && pos < size)
		{
			reverse_rotate_a(a);
			pos++;
		}
		push_b(a, b);
	}
	while (*b)
		push_a(a, b);
	free_lst(a);
	free_lst(b);
}
