
NAME = gnl

ifndef FILE
	FILE = broken_gnl.c
endif

compile:
	cc -Wall -Wextra -Werror *.c -o $(NAME)

run: compile
	./$(NAME) $(FILE)

val: compile
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(FILE)
