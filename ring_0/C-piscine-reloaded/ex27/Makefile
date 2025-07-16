CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = $(S)ft_display_file.c
OBJ = $(SRC:.c=.o)
EXEC = exec
RM = rm -f


all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(FLAGS) -o ft_display_file $(SRC) 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re




# -o = compil only (sans lier les fichiers objets pour generer l'executable)
# -c = specifie mane input
#
#LES APPELS SYSTEMES:

#0 Entree standard (ce que l'on entre ds le terminal)
#1 Sortie standard (ce qui s'affiche ds le terminal)
#2 Affiche les erreurs

#3 close = close file
#4 open = open file (return un identifiant (descripteur de fichier) qui est un int)
#5 read = read file (return le nombre d'octets lus)
#6 write = write file (return le nombre d'octets ecrits)) 
#  		Quand on appelle write, on précise trois choses
#  			-Le descripteur de fichier, qui indique où envoyer les données.
#  			-L'adresse de départ des données à envoyer.
#  			-La quantité d'octets à écrire.
#
#
