NAME=Nanoshell
SRC=./main.c
FLAGS=-Wall -Werror -Wextra

all:
	gcc $(FLAGS) -o $(NAME) $(SRC)