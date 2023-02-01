CFLAGS = -Wall -Werror -Wextra

CC = gcc

all:
	@cd ft_printf && make all
	@$(CC) $(CFLAGS) server.c ft_printf/printf.a -o server
	@$(CC) $(CFLAGS) client.c ft_printf/printf.a -o client

clean:
	@cd ft_printf && make clean
	@rm -rf server
	@rm -rf client

fclean: clean
	@cd ft_printf && make fclean

re: fclean all