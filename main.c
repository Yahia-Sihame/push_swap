#include "push_swap.h"

int main(int ac, char **av)
{
	int	**arr = parsed(ac, av);
	int i = 0;
	while(arr[i] != NULL)
	{
		printf("%d\n", *arr[i]);
		i++;
	}
	return 0;
}
