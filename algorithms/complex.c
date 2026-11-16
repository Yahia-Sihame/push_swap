#include "push_swap.h"
void	set_current_index(t_nums *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	set_target_b(t_nums *a, t_nums *b)
{
	long	best_match_value;
	t_nums	*current_a;
	t_nums	*target;

	while (b)
	{
		best_match_value = (long)MAX + 1;
		current_a = a;
		while (current_a)
		{
			if (b->num < current_a->num && current_a->num < best_match_value)
			{
				best_match_value = current_a->num;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_value == (long)MAX + 1)
			b->target_node = min_node(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

static void	min_on_top(t_nums **a, t_bench *bench)
{
	t_nums	*node_mine;

	set_current_index(*a);
	node_mine = min_node(*a);
	if (node_mine->above_median)
	{
		while (*a != node_mine)
			rotate_a(a, bench);
	}
	else
	{
		while (*a != node_mine)
			reverse_rotate_a(a, bench);
	}
}

void	sort_three(t_nums **a, t_bench *bench)
{
	t_nums	*biggest;

	biggest = max_node(*a);
	if (biggest == *a)
		rotate_a(a, bench);
	else if ((*a)->next == biggest)
		reverse_rotate_a(a, bench);
	if ((*a)->num > (*a)->next->num)
		swap_a(a, bench);
}

void	complex(t_nums **a, t_nums **b, t_bench *bench)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	if (len_a > 3 && !*b)
		push_b(a, b, bench);
	if (len_a > 4 && !(*b)->next)
		push_b(a, b, bench);
	len_a = ft_lstsize(*a);
	while (len_a > 3)
	{
		set_current_index(*a);
		set_current_index(*b);
		set_target_a(*a, *b);
		cost_analysis_a(*a, *b);
		set_cheapest(*a);
		push_cheapest_to_b(a, b, bench);
		len_a--;
	}
	sort_three(a, bench);
	push_b_to_a(a, b, bench);
	min_on_top(a, bench);
}
