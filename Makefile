
CC=		gcc -g -W -Wall -Wextra

RM=		rm -rfv

SRC=		main.c \
		basics.c \
		display.c

OBJ		= $(SRC:.c=.o

NAME=		Alum

LIB=		-lm

all:
		$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
		$(RM) $(OBJS_S) $(OBJS_C) *~

fclean:		clean
		$(RM) $(NAME_S) $(NAME_C)

re:		fclean all

.PHONY:		all clean fclean re
