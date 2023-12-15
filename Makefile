##
## EPITECH PROJECT, 2022
## generator Makefile
## File description:
## Makefile for lem_in
##

MAIN	=	src/main.c			 	\

SRC     = 	src/lem_in.c 			\
			src/pos.c				\
			src/node.c 				\
			src/cheak_param.c 		\
			src/module.c 			\
			src/new_connexion.c 	\
			src/path.c				\
			src/creat_path.c		\
			src/free.c				\
			src/mouv_ant.c 			\
			src/print.c				\
			src/check_path.c		\
			tests/open_file.c 		

TEST	=	tests/test_lemin.c 		\

OBJ     =	$(SRC:.c=.o)				\
			$(MAIN:.c=.o)

NAME    =	lem_in

CPPFLAGS +=		-I include

CFLAGS	+=		-g -Wall -Wextra

LDFLAGS	+=	-L ./lib -lmy

all: $(NAME)

$(NAME): 	lib
$(NAME):    $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

lib:
	make -C ./lib/my/

clean :
	-rm -f $(OBJ)

fclean:     clean
	-rm -f $(NAME)
	-rm -rf unit*
	make fclean -C ./lib/my/

re:     fclean all

tests_run:  re
	gcc -o unit_tests $(SRC) $(TEST) -Iinclude -lcriterion --coverage $(LDFLAGS)
	./unit_tests

.PHONY: lib re clean fclean all tests_run