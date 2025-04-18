##
## EPITECH PROJECT, 2024
## epitech-projects
## File description:
## makefile
##

NAME	=	A_bird

CFLAGS 	=	-Iinclude

SRC	=	./src/main.c \
        ./src/game.c \

OBJECTS	=	$(SRC:.c=.o)

all:	compilation

compilation:	$(OBJECTS)
	gcc $(OBJECTS) -o $(NAME) $(LIBS)

clean:
	rm	-f	$(OBJECTS)

fclean: clean
	rm	-f	$(NAME)

re:		fclean all

.PHONY:	all	clean	fclean	re
