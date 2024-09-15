NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = main.c main_2.c operations_1.c operations_2.c operations_3.c utils.c algo.c algo_2.c algo_3.c algo_4.c ft_split_to_int.c
OBJ = $(SRCS:.c=.o)

LIBFT = libft/libft.a
PRINTF = ./ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(GNL)
	$(CC) $(OBJ) $(CFLAGS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make all -C ./libft

$(PRINTF):
	make all -C ./ft_printf

clean:
	make clean -C ./libft
	make clean -C ./ft_printf
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	make fclean -C ./ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
