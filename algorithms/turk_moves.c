#include "../push_swap.h"

void	rotate_both(t_nums **a, t_nums **b, t_nums *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rr(a, b);
	set_current_index(*a);
	set_current_index(*b);
}

void	reverse_rotate_both(t_nums **a, t_nums **b, t_nums *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rrr(a, b);
	set_current_index(*a);
	set_current_index(*b);
}

void	prep_for_push(t_nums **stack, t_nums *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				rotate_a(stack);
			else
				reverse_rotate_a(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rotate_b(stack);
			else
				reverse_rotate_b(stack);
		}
	}
}

void	push_cheapest_to_b(t_nums **a, t_nums **b)
{
	t_nums	*cheap;
	t_nums	*target;

	cheap = get_cheapest(*a);
	target = cheap->target_node;
	if (cheap->above_median && target->above_median)
		rotate_both(a, b, cheap);
	else if (!cheap->above_median && !target->above_median)
		reverse_rotate_both(a, b, cheap);
	prep_for_push(a, cheap, 'a');
	prep_for_push(b, target, 'b');
	push_b(a, b);
}

void	push_b_to_a(t_nums **a, t_nums **b)
{
	while (*b)
	{
		set_current_index(*a);
		set_current_index(*b);
		init_nodes_b(*a, *b);
		prep_for_push(a, (*b)->target_node, 'a');
		push_a(a, b);
	}
}
