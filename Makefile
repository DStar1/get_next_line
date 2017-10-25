NAME = get_next_line

LIBF = libft/

SRC =	get_next_line.c \
		main.c

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make all -C libft
	gcc -g -o $(NAME) libft/libft.a $(SRC) 

clean:
	/bin/rm -f *.o
	make clean -C libft

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all
