##
## EPITECH PROJECT, 2021
## task01
## File description:
## D10
##

SRC	=	my_compute_power_rec.c 		\
		my_isneg.c 					\
		my_print_revalpha.c			\
		my_showmem.c				\
		my_strcmp.c					\
		my_str_isprintable.c		\
		my_strncmp.c				\
		my_compute_square_root.c	\
		my_is_prime.c				\
		my_putchar.c				\
		my_showstr.c				\
		my_strcpy.c					\
		my_str_isupper.c			\
		my_strncpy.c				\
		my_compute_factorial_it.c	\
		my_evil_str.c				\
		my_print_alpha.c			\
		my_put_nbr.c				\
		my_sort_int_array.c			\
		my_str_isalpha.c			\
		my_strlen.c					\
		my_strstr.c					\
		my_compute_factorial_rec.c	\
		my_find_prime_sup.c			\
		my_print_comb.c				\
		my_putstr.c					\
		my_strcapitalize.c			\
		my_str_islower.c			\
		my_strlowcase.c				\
		my_strupcase.c				\
		my_compute_power_it.c		\
		my_getnbr.c					\
		my_print_digits.c			\
		my_revstr.c					\
		my_strcat.c					\
		my_str_isnum.c				\
		my_strncat.c				\
		my_swap.c					\
		concat_params.c				\
		my_show_word_array.c		\
		my_str_to_word_array.c		\
		my_put_nbr_base.c			\
		my_printf.c					\
		w_flags.c					\
		char_spe.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

.PHONY: re fclean clean all
