##
## EPITECH PROJECT, 2018
## makefile
## File description:
## task01
##

SRC   =		my_put_nbr_unsigned.c	\
		my_revstr.c		\
		my_putstr.c		\
		flag_s.c		\
		my_put_nbr.c		\
		my_put_nbr_octal.c	\
		my_printf.c

CFLAGS =	-W  -Wextra -Wall

OBJ   =	    $(SRC:.c=.o)

NAME	= 	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: 	fclean all

auteur:
	echo $(USER) > auteur
