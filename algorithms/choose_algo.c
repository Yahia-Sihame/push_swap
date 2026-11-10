/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:27:55 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/07 12:42:28 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//---> algo:
//1 : simple.
//2 : medium.
//3 : complex.
//4 : adaptive.


static void	check_algo2(char **strs, int *algo, int **bensh, int *check_dup)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (check_algo(strs[i]))
		{
			if (!ft_strcmp(strs[i], BNSH))
			{
				(**bensh)++;
				(*check_dup)--;
			}
			if (!ft_strcmp(strs[i], SMPL))
				*algo = 1;
			else if (!ft_strcmp(strs[i], MD))
				*algo = 2;
			else if (!ft_strcmp(strs[i], CMPLX))
				*algo = 3;
			else if (!ft_strcmp(strs[i], ADPT))
				*algo = 4;
			(*check_dup)++;
		}
		i++;
	}
}

int	choose(int ac, char **av, int *bensh)
{
	char	**strs;
	int	algo;
	int	check_dup;

	check_dup = 0;	
	algo = 0;
	strs = parse_args(ac, av);
	if (!strs)
		free_exit(NULL,NULL);
	check_algo2(strs, &algo, &bensh, &check_dup);
	free_strs(strs);
	if (check_dup > 1 || *bensh > 1)
		free_exit(NULL, NULL);

	if (algo == 0)
		return (4);
	return (algo);
}
