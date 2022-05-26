NAME = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =	main.c \
		sort.c \
		utils.c \
		bubble.c \
		quick_sort.c \
		operations/swap.c \
		operations/rotate.c \
		operations/push.c \
		operations/reverse_rotate.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
