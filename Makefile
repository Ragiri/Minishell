##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make files
##

NAME	=	mysh

SRC	=	src/my_cd.c 	\
		src/function.c 		\
		src/function_two.c		\
		src/env.c			\
		src/unset.c			\
		src/mysh.c

OBJ	=	$(SRC:.c=.o)

CPPFLAGS += -I./include

LIB	=	-L./my_printf/ -lmy

CFLAGS	=	-W -Wextra -Wall -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C my_printf/
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIB) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	make fclean -C my_printf
	rm -f $(NAME)
	rm -f *~
	rm -f *#

re:	fclean clean all

test_run:
			make -C my_printf/
			make -C tests/
			make fclean -C tests/
			make fclean -C my_printf/

.PHONY:	all re clean fclean
