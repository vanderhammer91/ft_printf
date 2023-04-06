NAME	= libftprintf.a

SOURCES	=	./sources/get_printchar_length.c		\
			./sources/get_printstr_length.c			\
			./sources/get_printdecimal_length.c		\
			./sources/get_printunsignedint_length.c	\
			./sources/get_printaddress_length.c		\
			./sources/get_printhex_length.c			\
			./sources/ft_printf.c 					\

OBJECTS	= $(SOURCES:.c=.o)

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJECTS)
			ar rcs $(NAME) $(OBJECTS)

clean:
			$(RM) $(OBJECTS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
