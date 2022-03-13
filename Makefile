NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC_FILES = push_swap.c \
			get_lis.c \
			index_calculation.c \
			little_sort.c \
			push_swap.c \
			pusher_from_b.c \
			starting_position.c \
			tools.c \
			tools2.c \
			tools3.c \
			tools4.c \
			tools5.c \
			tools_for_little_sort.c \
			tools_for_little_sort2.c \
			tools_for_little_sort3.c
OBJ_FILES = $(SRC_FILES:.c=.o)
HEADER = push_swap.h
RM = rm -rf

all:	libft $(NAME)

libft:  libft/libft.a

libft/libft.a:
	$(MAKE) -C libft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ libft/libft.a -o $@

clean:
	$(MAKE) fclean -C libft
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
