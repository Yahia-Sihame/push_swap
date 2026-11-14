NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_print_add.c \
	ft_print_char.c \
	ft_printf.c \
	ft_print_lowhex.c \
	ft_print_num.c \
	ft_print_str.c \
	ft_print_uint.c \
	ft_print_uphex.c \
	ft_check.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re
