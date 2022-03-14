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
			tools_for_little_sort.c \
			tools_for_little_sort2.c \
			tools_for_little_sort3.c

TOOLS = tools.c \
			tools2.c \
			tools3.c \
			tools4.c \
			tools5.c
TOOLS_OBJS = $(TOOLS:.c=.o)

BONUS_SRC_FILES = checker_bonus.c tools_bonus.c tools2_bonus.c
BONUS_OBJ_FILES = $(BONUS_SRC_FILES:.c=.o)

CHECKER = checker

OBJ_FILES = $(SRC_FILES:.c=.o)
HEADER = push_swap.h
RM = rm -rf

all:	libft $(NAME)

libft:  libft/libft.a

libft/libft.a:
	$(MAKE) -C libft

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJ_FILES) $(TOOLS_OBJS)
	$(CC) $(CFLAGS) $^ libft/libft.a -o $@

clean:
	$(MAKE) fclean -C libft
	$(RM) $(OBJ_FILES) $(TOOLS_OBJS) $(BONUS_OBJ_FILES)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

bonus: $(CHECKER)

$(CHECKER): libft $(BONUS_OBJ_FILES) $(TOOLS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJ_FILES) $(TOOLS_OBJS) libft/libft.a -o $@

.PHONY: libft all clean fclean re bonus
