##
## EPITECH PROJECT, 2019
## PSU_navy_2018
## File description:
## Makefile
##

SRC = main.c src/utils/my_get_nbr.c src/utils/write.c \
	  src/connection/connect.c src/signal/signal.c \
	  src/utils/str_word_array.c \
	  src/send/send_check.c src/utils/read.c \
	  src/map/get_map.c src/map/shot.c \
	  src/map/check_map.c \
	  src/players_turn/player1.c \
	  src/players_turn/player2.c \
	  src/error/error.c \
	  src/error/size_error.c \
	  src/error/error_boat.c

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra

NAME = navy

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: clean fclean all