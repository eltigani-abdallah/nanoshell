NAME=Nanoshell
SRC=main.c src/ls.c
FLAGS=-Wall -Werror -Wextra
#FLAGS=-Wall -Werror

all:
	gcc $(FLAGS) -o out/$(NAME) $(SRC)