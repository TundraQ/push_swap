NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC_FILES = push_swap.c dblist.c main.c stack.c
OBJ_FILES = $(SRC_FILES:.c=.o)
HEADER = push_swap.h
RM = rm -rf
all:	$(NAME)
%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $<
$(NAME): $(OBJ_FILES)
		$(CC) $(CFLAGS) libft/libft.a $^ -o $@
clean:
	$(RM) $(OBJ_FILES)
fclean: clean
		$(RM) $(NAME)
re: fclean all
.PHONY: clean fclean re
