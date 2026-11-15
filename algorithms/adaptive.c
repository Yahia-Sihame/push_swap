#include "../push_swap.h"

void  adaptive(t_nums **head_a, t_nums **head_b, t_bench *bench, int ac, char **av)
{
    double  disorder;

    disorder = compute_disorder(ac, av);
    if (disorder < 20.0)
      simple(head_a, head_b, bench);
    else if (disorder < 50.0)
      medium(head_a, head_b, bench);
    else
      complex(head_a, head_b, bench);
}
