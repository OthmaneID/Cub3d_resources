FILES=tuto.c mlx_utils.c
OBJ=$(FILES:.c=.o)
NAME=tuto
CFLAGS=-Imlx -lmlx
CC=gcc

all:$(NAME)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) -fsanitize=address
clean:
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re:clean all