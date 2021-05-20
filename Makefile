##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## projet solo 1
##
SRC	=	$(wildcard *.c) \
		AddiSoustraction/infin_add.c \
		AddiSoustraction/plus_moins.c \
		AddiSoustraction/plus_moins2.c \
		AddiSoustraction/plus_moins3.c \
		AddiSoustraction/plus_plus_add.c \
		Modulo/modulo.c \
		Division/division.c \
		Division/division2.c \
		Division/division3.c \
		Division/division4.c \
		Division/int_to_str.c \
		Division/Division_Simple/division1.c \
		Division/Division_Simple/division2.c \
		Division/Division_Simple/division3.c \
		Division/Modulo_Simple/modulo1.c \
		Multiplication/multiplication.c \
		Multiplication/plus_plus.c \
		Multiplication/plus_plus2.c

OBJ	=	$(SRC:.c=.o) \

NAME 	=	calc

CFLAGS	=	-I./include/

LDFLAGS =	-lmy -L./lib/

all:	$(NAME)

$(NAME):	$(OBJ) lib/libmy.a
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) ./lib/my/*~
	$(RM) *~
	$(RM) $(OBJ)
	$(MAKE) -C ./lib/my/ clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C ./lib/my/ fclean
	cd lib/ && rm libmy.a

re:	fclean all

lib/libmy.a:
	$(MAKE) -C ./lib/my/

.Phony: all clean fclean re
