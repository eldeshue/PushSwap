# result file name
NAME = push_swap
NAME_B = push_swap_bonus

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./ft_deque -lftdeque

# path
FT_DEQUE_DIR = ./ft_deque
LIBFT_DIR = ./libft

SRCS = ./src/main.c \

SRCS_B = ./bonus/main_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all		: $(NAME)

bonus	: $(NAME_B)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(MAKE) -C $(FT_DEQUE_DIR)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

$(NAME_B) : $(OBJS_B)
	$(MAKE) -C $(FT_DEQUE_DIR)
	$(CC) $(LDFLAGS) $(OBJS_B) -o $@

clean:
	$(MAKE) -C $(FT_DEQUE_DIR) clean
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	$(MAKE) -C $(FT_DEQUE_DIR) fclean
	rm -f $(NAME) $(NAME_B)

re:
	make fclean
	make all

.PHONY: clean fclean re all bonus
