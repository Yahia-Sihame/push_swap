/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 22:18:15 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/06 18:07:29 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 2147483647
#define MIN -2147483648

#define SMPL "--simple"
#define MD "--medium"
#define CMPLX "--complex"
#define BNCH "--bensh"
#define ADPT "--adaptive"


typedef struct s_nums
{
	int		num;
	struct s_nums	*next;
	struct s_nums	*prev;
}	t_nums;

char	**parse_args(int ac, char **av);
int	**parsed(int ac, char **av);
void	free_ints(int **arr);
void	free_strs(char **arr);
void	err_msg(int ac, char **av);
void	free_exit(int **ints, char **arr);
void	check_dup(int **ints);

long	ft_atoi(const char *str, int **ints, char **arr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_lstadd_back(t_nums **alst, t_nums *new);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int	ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
int	check_algo(char *str);

t_nums	*ft_lstnew(int num);
void	ft_lstadd_back(t_nums **lst, t_nums *new);
t_nums  *fill_lst(int ac, char **av);
void	free_lst(t_nums **head);

int	choose(int ac, char **av);
#endif
