NAME 	= 	push_swap
CC 		= 	cc
CFLAGS 	= 	-Wall -Wextra -Werror
RM 		= 	rm -rf
SRCS 	= 	main.c utils.c utils2.c operations.c operations2.c sort.c \
			libft_funcs.c libft_funcs2.c checks.c init_stack.c init_stack2.c \

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