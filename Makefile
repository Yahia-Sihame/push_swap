
NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I./ft_printf

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

SRCS = push_swap.c \
		algorithms/choose_algo.c \
		algorithms/complex.c \
		algorithms/medium.c \
		algorithms/simple.c \
		algorithms/adaptive.c \
		algorithms/bench.c \
		algorithms/disorder.c\
		algorithms/turk_cost.c\
		algorithms/turk_moves.c\
		algorithms/turk_utils.c\
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
		utils/ft_putdouble.c\
		utils/ft_putnbr_fd.c \
		utils/ft_putchar_fd.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

