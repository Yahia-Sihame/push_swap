NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
			algorithms/choose_algo.c\
			algorithms/complex.c\
			algorithms/medium.c\
			algorithms/simple.c\
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
			utils/ft_strlen.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
