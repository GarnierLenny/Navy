##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make
##

SRC		=	src/base_convert_str.c\
			src/int_to_str.c\
			src/usage.c\
			src/get_info.c\
			src/send_char_sig.c\
			src/get_sig_str.c\
			src/disp_ss.c\
			src/my_str_to_word_array_sep.c\
			src/set_map_empty.c\
			src/game_loop.c\
			src/check_hit.c\
			src/check_x_nb.c\
			src/check_both_map_x.c\
			src/error_cases.c\

SRC_M	=	src/main.c

SRC_UT	=	tests/*.c

OBJ		=	$(SRC:.c=.o)

OBJ_M	=	$(SRC_M:.c=.o)

OBJ_UT	=	$(SRC_UT:.c=.o)

INCLUDE	=	-I./include -I../include -I../../include

NAME	=	navy

NAME_UT	=	unit_tests

CFLAGS	=	-W -Werror -Wall -Wextra -I./include

CFLAGS_UT	=	-lcriterion --coverage -lgcov

LIB		=	-L lib/ -lmy

RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ_M) $(OBJ)
		make -C lib/my/
		gcc -o $(NAME) $(OBJ) $(OBJ_M) $(INCLUDE) $(CFLAGS) $(LIB)

tests_run:	$(OBJ) $(OBJ_UT)
		make -C lib/my/
		gcc -o $(NAME_UT) $(SRC) $(SRC_UT) $(INCLUDE) $(CFLAGS_UT) $(LIB)
		./$(NAME_UT)
		gcovr -e tests

clean:
		$(RM) $(OBJ) $(OBJ_M) lib/my/*.o lib/libmy.a lib/my/libmy.a *gcno *gcda *~

fclean:		clean fclean_ut
		$(RM) $(NAME) tests/*.o

fclean_ut: clean
		$(RM) $(NAME_UT)

re:		fclean all