CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar -rcs
HEADER = -Ilibft
SRC = 	main.c \
	 	swap.c \
	 	rotate.c \
	 	reverse_rotate.c \
		push.c \
		display_stack.c \
		sort.c \
		search.c \
		search_next.c \
		check.c \
		parsing.c \
		free.c \
		first.c \
		algo.c \
		count.c \
		init.c \
		algo_next.c
OBJ = $(SRC:.c=.o)
EXEC = exec
LLDB = -g3
NAME = push_swap
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(FLAGS) $(LLDB) $^ -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft
	$(MAKE) bonus -C libft

$(FT_PRINTF):
	$(MAKE) -C ft_printf

%.o: %.c
	$(CC) $(FLAGS) $(LLDB) -c $< -o $@

clean:
	$(MAKE) clean -C libft
	$(MAKE) clean -C ft_printf
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C ft_printf
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean clean fclean re
