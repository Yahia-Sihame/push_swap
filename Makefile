
NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes 

PRINTF_DIR = ft_printf
PRINTF_LIB = ft_printf/libftprintf.a

SRCS = push_swap.c \
		algorithms/choose_algo.c \
		algorithms/complex.c \
		algorithms/medium.c \
		algorithms/simple.c \
		algorithms/adaptive.c \
		algorithms/bench.c \
		algorithms/disorder.c \
		algorithms/turk_cost.c \
		algorithms/turk_moves.c \
		algorithms/turk_utils.c \
		opperations/fill_lst.c \
		opperations/push.c \
		opperations/reverse.c \
		opperations/rotate.c \
		opperations/swap.c \
		parsing/check_dup.c \
		parsing/err_msg.c \
		parsing/parse_args.c \
		utils/free_arrs.c \
		utils/ft_atoi.c \
		utils/ft_bzero.c \
		utils/ft_calloc.c \
		utils/ft_lstadd_back.c \
		utils/ft_lstnew.c \
		utils/ft_lstsize.c \
		utils/ft_split.c \
		utils/ft_strchr.c \
		utils/ft_strcmp.c \
		utils/ft_strjoin.c \
		utils/ft_strlen.c \
		utils/ft_putdouble.c \
		utils/ft_putnbr_fd.c \
		utils/ft_putchar_fd.c

BONUS_SRCS = checker_bonus/checker.c \
		checker_bonus/opperations/fill_lst.c \
		checker_bonus/opperations/push.c \
		checker_bonus/opperations/reverse.c \
		checker_bonus/opperations/rotate.c \
		checker_bonus/opperations/swap.c \
		checker_bonus/utils/free_arrs.c \
		checker_bonus/utils/ft_atoi.c \
		checker_bonus/utils/ft_bzero.c \
		checker_bonus/utils/ft_calloc.c \
		checker_bonus/utils/ft_lstadd_back.c \
		checker_bonus/utils/ft_lstnew.c \
		checker_bonus/utils/ft_lstsize.c \
		checker_bonus/utils/ft_split.c \
		checker_bonus/utils/ft_strchr.c \
		checker_bonus/utils/ft_strcmp.c \
		checker_bonus/utils/ft_strjoin.c \
		checker_bonus/utils/ft_strlen.c \
		parsing/check_dup.c \
		parsing/err_msg.c \
		parsing/parse_args.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) -o $(NAME)

$(BONUS): $(BONUS_OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(PRINTF_LIB) -o $(BONUS)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re

