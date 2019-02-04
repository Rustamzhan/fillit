NAME = fillit
SRCS = ./srcs/ft_clear_2d_arr.c ./srcs/ft_lst_len.c ./srcs/ft_sqrt_up.c\
	  ./srcs/main.c ./srcs/point.c ./srcs/print_board.c ./srcs/save_coords.c\
	  ./srcs/solve.c ./srcs/tetromino.c ./srcs/validating_file.c
OBJECTS = ft_clear_2d_arr.o ft_lst_len.o ft_sqrt_up.o main.o point.o\
		 print_board.o save_coords.o solve.o tetromino.o validating_file.o

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc -c -Wall -Wextra -Werror $(SRCS) -I libft/includes
	gcc $(OBJECTS) -o $(NAME) -I libft/includes -L libft/ -lft

clean:
	rm -f $(OBJECTS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all