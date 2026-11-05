/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 15:33:27 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/04 22:54:51 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	freearr(char **arr, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	countword(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	fillstr(char **str, char const *s, char c, int start)
{
	int	i;
	int	end;

	end = start;
	while (s[end] != c && s[end])
		end++;
	*str = malloc(end - start + 1);
	if (!(*str))
		return (0);
	i = 0;
	while (start < end)
	{
		(*str)[i] = s[start];
		start++;
		i++;
	}
	(*str)[i] = 0;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		x;

	arr = ft_calloc(sizeof(char *), (countword(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		i += fillstr(&(arr[x]), s, c, i);
		if (!arr[x])
		{
			freearr(arr, x);
			return (NULL);
		}
		x++;
	}
	return (arr);
}
