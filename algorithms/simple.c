#include "../push_swap.h"

void simple(t_nums **head_a, t_nums **head_b)
{
    int size;
    int i;

    while (*head_a)
    {
        size = ft_lstsize(*head_a);
        i = 0;
        while (i < size - 1)
        {
            reverse_rotate_a(head_a);
            if ((*head_a)->num > (*head_a)->next->num)
                swap_a(head_a);
            i++;
        }
        push_b(head_a, head_b);
    }
    while (*head_b)
        push_a(head_a, head_b);
    free_lst(head_a);
    free_lst(head_b);
}
