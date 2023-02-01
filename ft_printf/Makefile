NAME = printf.a

SRCS = ft_count_return.c ft_percentage_p.c ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr_base.c ft_putnbr.c ft_putstr.c ft_strlen.c ft_uns_putnbr.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all