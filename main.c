#include "push_swap.h"


int main(int ac, char **av)
{
	int **ints = parsed(ac, av);
	int i = 0;
	while(ints[i] != NULL)
	{
		printf("%d\n", *ints[i]);
		i++;
	}
	return 0;
}
