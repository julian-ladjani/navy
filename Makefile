##
## Makefile for Project in /home/shielder/Projects/
##
## Made by Maxime PICOT
## Login   <shielder@epitech.net>
##
## Started on  Mon Nov 21 09:49:22 2016 Maxime PICOT
## Last update Wed Feb  1 12:13:51 2017 Maxime PICOT
##

COMP	=	gcc

SRC	=	src/	\

CFLAGS	=	-I./include/ -Wall -Wextra -g

LDLIBS	=	-L./lib/my

LDFLAGS	=	-lmy -lmypf -lgnl

OBJ	=	$(SRC:src/%.c=obj/%.o)

RM	=	rm -f

NAME	=	navy

all:		$(NAME)

$(NAME):	$(OBJ)
		$(COMP) -o $(NAME) $(OBJ)  $(LDLIBS) $(LDFLAGS)

obj/%.o:	src/%.c
		@mkdir -p obj/
		$(COMP) -o $@ -c $< $(CFLAGS)

clean:
		$(RM) $(OBJ)
		$(RM) -rf obj/

fclean: 	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
