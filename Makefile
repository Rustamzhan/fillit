NAME=fillit
SRCS=*.c
OBJECTS=$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	make -C libft/ clean
	gcc -c -g -Wall -Wextra -Werror $(SRCS) -I libft/includes
	gcc -g $(OBJECTS) -o $(NAME) -I libft/includes -L libft/ -lft

clean:
	rm -f $(OBJECTS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all