CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
HD = *.h
SRC = ft_printf.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putnbr.c \
	  ft_putnbr_unsigned.c \
	  ft_putnbr_exa.c \
	  check_p.c \
	  ft_strlen.c 
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a


all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re :fclean all

.PHONY: all clean fclean re
