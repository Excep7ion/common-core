NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRC = src/ft_isalpha.c \
	 src/ft_isdigit.c \
	 src/ft_isalnum.c \
	 src/ft_isascii.c \
	 src/ft_isprint.c \
	 src/ft_strlen.c \
	 src/ft_memset.c \
	 src/ft_bzero.c \
	 src/ft_memcpy.c \
	 src/ft_memmove.c \
	 src/ft_strlcpy.c \
	 src/ft_strlcat.c \
	 src/ft_toupper.c \
	 src/ft_tolower.c \
	 src/ft_strchr.c \
	 src/ft_strrchr.c \
	 src/ft_strncmp.c \
	 src/ft_memchr.c \
	 src/ft_memcmp.c \
	 src/ft_strnstr.c \
	 src/ft_atoi.c \
	 src/ft_atol.c \
	 src/ft_calloc.c \
	 src/ft_strdup.c \
	 src/ft_split.c \
	 src/ft_substr.c \
	 src/ft_strjoin.c \
	 src/ft_strtrim.c \
	 src/ft_itoa.c \
	 src/ft_strmapi.c \
	 src/ft_striteri.c \
	 src/ft_putchar_fd.c \
	 src/ft_putstr_fd.c \
	 src/ft_putendl_fd.c \
	 src/ft_putnbr_fd.c \
	 src/ft_sqrt.c
	 
SRC_BONUS =	src/ft_lstnew_bonus.c \
 	 		src/ft_lstadd_front_bonus.c \
 	 		src/ft_lstsize_bonus.c \
 	 		src/ft_lstlast_bonus.c \
 	 		src/ft_lstadd_back_bonus.c
 	 		#src/ft_lstdelone_bonus.c 
 	 		#src/ft_lstclear_bonus.c 
 	 		#src/ft_lstiter_bonus.c 
 	 		#src/ft_lstmap_bonus.c
OBJ = $(SRC:src/%.c=obj/%.o)
OBJ_BONUS = $(SRC_BONUS:src/%.c=obj/%.o)
AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Creation of $(NAME)...$(NC)"
	$(AR) $(NAME) $(OBJ)
	@echo "$(BLINK)$(GREEN)Archive created $(LIBFT)$(NC)"

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(OBJ) $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	$(RM) $(OBJ)
	$(RM) -r obj

clean_bonus:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean clean_bonus
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean_bonus clean fclean re
