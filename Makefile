NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = main.c utils.c utils2.c operations.c operations2.c sort.c sort_basic.c checks.c stack_init.c\
		libft/ft_atoi.c libft/ft_split.c libft/ft_isdigit.c libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strchr.c

all:
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

git:
	@make fclean
	@git add .
	@git status
	@read -p "Enter commit message: " message; \
	git commit -m "$$message"
	@git push
	@git log

.PHONY = all clean fclean re