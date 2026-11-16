#include "push_swap.h"

void	set_target_a(t_nums *a, t_nums *b)
{
	t_nums	*target;
	t_nums	*currentb;
	long	index;

	while (a)
	{
		index = (long)MIN - 1;
		currentb = b;
		while (currentb)
		{
			if (a->num > currentb->num && currentb->num > index)
			{
				index = currentb->num;
				target = currentb;
			}
			currentb = currentb->next;
		}
		if (index == (long)MIN - 1)
			a->target_node = max_node(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

static void	assign_cost(t_nums *a, int cost_a, int cost_b)
{
	if (a->above_median == a->target_node->above_median)
	{
		if (cost_a > cost_b)
			a->push_cost = cost_a;
		else
			a->push_cost = cost_b;
	}
	else
		a->push_cost = cost_a + cost_b;
}

void	cost_analysis_a(t_nums *a, t_nums *b)
{
	int	len_a;
	int	len_b;
	int	cost_a;
	int	cost_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (a)
	{
		if (a->above_median)
			cost_a = a->index;
		else
			cost_a = len_a - a->index;
		if (a->target_node->above_median)
			cost_b = a->target_node->index;
		else
			cost_b = len_b - a->target_node->index;
		assign_cost(a, cost_a, cost_b);
		a = a->next;
	}
}
