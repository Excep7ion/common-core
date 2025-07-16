CC = cc
AR = ar rcs
FLAGS = -Wall -Wextra -Werror
S = srcs/
H = includes/
SRC = $(S)ft_putchar.c \
	  $(S)ft_putstr.c \
	  $(S)ft_strcmp.c \
	  $(S)ft_strlen.c \
	  $(S)ft_swap.c
OBJ = $(SRC:.c=.o)
NAME = libft.a
EXEC = exec


all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re




# -o = compil only (sans lier les fichiers objets pour generer l'executable)
# -c = specifie mane input
# ar rcs = r = replace, remplace les anciens fichiers de la bibliotheque par les nouveaux
# 		 = c = create, creer la bibliotheque si elle n'existe pas
# 		 = s = sort, creer un index trie de la bibliotheque  
# ar -t libft.a = voir le contenue de la bibliotheque
#
#-I $(H)
