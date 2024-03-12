NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = main.c utils.c libft/ft_atoi.c

all:
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY = all clean fclean re