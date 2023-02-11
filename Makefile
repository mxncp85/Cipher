##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC     =	src/main.c 	\
			src/encryption.c 	\
			src/decryption.c

OBJ =   $(SRC:.c=.o)

#CFLAGS = -W -Wall -Wextra -Wshadow -Werror -lm

NAME =  103cipher

all:    $(NAME)

$(NAME):    $(OBJ)
		gcc -o $(NAME) $(SRC)
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
