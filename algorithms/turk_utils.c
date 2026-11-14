#include "../push_swap.h"

t_nums	*max_node(t_nums *t)
{
	t_nums	*max;
	long	max_value;

	if (!t)
		return (NULL);
	max_value = (long)MIN - 1;
	while (t)
	{
		if ((long)t->num > max_value)
		{
			max_value = t->num;
			max = t;
		}
		t = t->next;
	}
	return (max);
}

t_nums	*min_node(t_nums *t)
{
	t_nums	*min;
	long	min_value;

	if (!t)
		return (NULL);
	min_value = (long)MAX + 1;
	while (t)
	{
		if ((long)t->num < min_value)
		{
			min_value = t->num;
			min = t;
		}
		t = t->next;
	}
	return (min);
}

void	set_cheapest(t_nums *stack)
{
	long	cheapest_value;
	t_nums	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = (long)MAX + 1;
	while (stack)
	{
		stack->cheapest = 0;
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

t_nums	*get_cheapest(t_nums *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
