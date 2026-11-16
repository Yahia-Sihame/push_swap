
#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_nums
{
	int				num;
	struct s_nums	*next;
	struct s_nums	*prev;
}	t_nums;

// Parsing
char	**parse_args(int ac, char **av);
int		**parsed(int ac, char **av);
void	free_ints(int **arr);
void	free_strs(char **arr);
void	err_msg(int ac, char **av);
void	free_exit(int **ints, char **arr);
void	check_dup(int **ints);

// Utils
long	ft_atoi(const char *str, int **ints, char **arr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
void	ft_lstadd_back(t_nums **alst, t_nums *new);
t_nums	*ft_lstnew(int num);

// Checker list functions
t_nums	*fill_lst(int ac, char **av);
void	free_lst(t_nums **head);

// Swap
void	swap_a(t_nums **head_a);
void	swap_b(t_nums **head_b);
void	ss(t_nums **head_a, t_nums **head_b);

// Push
void	push_a(t_nums **head_a, t_nums **head_b);
void	push_b(t_nums **head_b, t_nums **head_a);

// Rotate
void	rotate_a(t_nums **head_a);
void	rotate_b(t_nums **head_b);
void	rr(t_nums **head_a, t_nums **head_b);

// Reverse rotate
void	reverse_rotate_a(t_nums **head_a);
void	reverse_rotate_b(t_nums **head_b);
void	rrr(t_nums **head_a, t_nums **head_b);

#endif

