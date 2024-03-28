NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = main.c utils.c utils2.c operations.c operations2.c operations_sim.c sort_old.c sort_old2.c sort_old3.c sort_old4.c sort.c \
		libft/ft_atoi.c libft/ft_putendl_fd.c libft/ft_split.c

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