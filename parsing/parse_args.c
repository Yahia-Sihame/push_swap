/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 22:08:47 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/05 15:46:28 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	**parse_args(int ac, char **av)
{
	char	*tmp;
	char	*all;
	char	**res;
	int	i;
	
	i = 1;
	all = malloc(sizeof(char));
	if (!all)
		return (NULL);
	all[0] = 0;
	while (i < ac)
	{
		tmp = ft_strjoin(all, av[i]);
		free(all);
		if (!tmp)
			return (NULL);
    		all = ft_strjoin(tmp, " ");
		free(tmp);
		if (!all)
			return (NULL);
	        i++;
	}	       
	res = ft_split(all, ' ');
	free(all);
	return (res);
}

static int	len_arr(char **arr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (arr[i])
	{
		if(!check_algo(arr[i]))
			len++;
		i++;
	}
	return (len);
}

static long	check_for_max(int **ints, char *s)
{
	long	n;

	n = ft_atoi(s, ints);
	if (n > MAX || n < MIN)
	{
		free_ints(ints);
		write (2, "Error\n", 6);
		exit (1);
	}
	return (n);
}

static int	**to_int(char **arr)
{
	int	len;
	int	**ints;
	int	j;

	ints = malloc(sizeof(int *) * (len_arr(arr) + 1));
	if (!ints)
		return (NULL);
	j = 0;
	len = 0;
	while (arr[len])
	{
		if (!check_algo(arr[len]))
		{
			ints[j] = malloc(sizeof(int));
			if (!ints[j])
				return (NULL);
			*ints[j] = (int )check_for_max(ints, arr[len]);
			j++;
		}
		free(arr[len]);
		len++;
	}
	free(arr);
	ints[j] = NULL;
	return (ints);
}

int	**parsed(int ac, char **av)
{
	char	**strs;
	int	**ints;
	int	x;
	int	y;

	err_msg(ac, av);
	strs = parse_args(ac, av);
	ints = to_int(strs);	
	x = 0;
	while (ints[x])
	{
		y = x + 1;
		while (ints[y])
		{
			if (*ints[x] == *ints[y])
			{
				free_ints(ints);
				write (2, "Error\n", 6);
				exit (1);
			}
			y++;
		}
		x++;
	}
	return (ints);
}
