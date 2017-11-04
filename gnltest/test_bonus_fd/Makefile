# compiler
CC		=	clang

# file type
FT		=	c

# flags
FLAGS	=	-Wall -Wextra -Werror
FLAGS	+=	-g3

# executable
NAME	=	test_gnl

# to compile files
SRC		=	main.c
SRC		+=	test_multiple_fd.c
SRC		+=	get_next_line.c

# header files
HDR		=	get_next_line.h
HDR		+=	tests.h

# objects files
OBJS	=	$(SRC:.$(FT)=.o)

RM		=	/bin/rm

# main rule
all: $(NAME)

# rebuild your bin
re: fclean all

# compile lib
$(NAME): $(OBJS)
	$(CC) -o $@ $(OBJS) -I libft/includes -I libft/ -L libft/ -lft

# making o files
%.o: %.$(FT)
	$(CC) -I libft/includes -I libft/ -o $@ -c $< $(FLAGS)

# protect commands
.PHONY: all re clean fclean

# clean o files
clean:
	$(RM) -f $(OBJ)

# clean exec file and library
fclean: clean
	$(RM) -f $(NAME)
