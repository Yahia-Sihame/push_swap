/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebajja <ebajja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:22:25 by ebajja            #+#    #+#             */
/*   Updated: 2026/11/16 16:44:02 by ebajja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"

# define MAX 2147483647
# define MIN -2147483648

# define SMPL "--simple"
# define MD "--medium"
# define CMPLX "--complex"
# define BNSH "--bench"
# define ADPT "--adaptive"

typedef struct s_nums
{
	int				num;
	int				index;
	int				above_median;
	int				push_cost;
	int				cheapest;
	struct s_nums	*target_node;
	struct s_nums	*next;
	struct s_nums	*prev;
}	t_nums;

typedef struct s_bench
{
	int		bench;
	double	disorder;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;

//---> algo:
//1 : simple.
//2 : medium.
//3 : complex.
//4 : adaptive.
//------>PARSING:
char	**parse_args(int ac, char **av);
int		**parsed(int ac, char **av);
void	free_ints(int **arr);
void	free_strs(char **arr);
void	err_msg(int ac, char **av);
void	free_exit(int **ints, char **arr);
void	check_dup(int **ints);

//------->UTILS:
long	ft_atoi(const char *str, int **ints, char **arr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_lstadd_back(t_nums **alst, t_nums *new);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
int		check_algo(char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putdouble(double num);
void	ft_putchar_fd(char c, int fd);

//------>LINKED LISTS UTILS:
t_nums	*ft_lstnew(int num);
void	ft_lstadd_back(t_nums **lst, t_nums *new);
t_nums	*fill_lst(int ac, char **av);
void	free_lst(t_nums **head);
int		ft_lstsize(t_nums *lst);

//------->ALGOS:
int		choose(int ac, char **av, int *bench);

//-----opperations:
//--->swap:
void	swap_a(t_nums **head_a, t_bench *bench);
void	swap_b(t_nums **head_b, t_bench *bench);
void	ss(t_nums **head_a, t_nums **head_b, t_bench *bench);
//--->push:
void	push_a(t_nums **head_a, t_nums **head_b, t_bench *bench);
void	push_b(t_nums **head_b, t_nums **head_a, t_bench *bench);
//--->rotate:
void	rotate_a(t_nums **head_a, t_bench *bench);
void	rotate_b(t_nums **head_b, t_bench *bench);
void	rr(t_nums **head_a, t_nums **head_b, t_bench *bench);
//--->reverse rotate:
void	reverse_rotate_a(t_nums **head_a, t_bench *bench);
void	reverse_rotate_b(t_nums **head_b, t_bench *bench);
void	rrr(t_nums **head_a, t_nums **head_b, t_bench *bench);
//--->sort:
void	simple(t_nums **head_a, t_nums **head_b, t_bench *bench);
void	medium(t_nums **head_a, t_nums **head_b, t_bench *bench);
void	complex(t_nums **head_a, t_nums **head_b, t_bench *bench);
void	adaptive(t_nums **head_a, t_nums **head_b, t_bench *bench,
			double disorder);

// --->disorder:
double	compute_disorder(int ac, char **av);
void	ft_bench(t_bench *bench, int algo);

// --->Turk Sort (Phase 1):
void	set_current_index(t_nums *stack);
t_nums	*max_node(t_nums *t);
t_nums	*min_node(t_nums *t);
void	set_target_a(t_nums *a, t_nums *b);
void	cost_analysis_a(t_nums *a, t_nums *b);
void	set_cheapest(t_nums *stack);
t_nums	*get_cheapest(t_nums *stack);

// --->Turk Sort (Phase 2):
void	rotate_both(t_nums **a, t_nums **b, t_nums *cheapest_node,
			t_bench *bench);
void	reverse_rotate_both(t_nums **a, t_nums **b, t_nums *cheapest_node,
			t_bench *bench);
void	prep_for_push(t_nums **stack, t_nums *top_node, char stack_name,
			t_bench *bench);
void	push_cheapest_to_b(t_nums **a, t_nums **b, t_bench *bench);
void	set_target_b(t_nums *a, t_nums *b);
void	push_b_to_a(t_nums **a, t_nums **b, t_bench *bench);

#endif