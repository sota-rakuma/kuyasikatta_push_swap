CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
SHARED_SRCS = init_bcl.c\
	rule_def_1.c\
	rule_def_2.c\
	rule_def_3.c\
	check_alignment.c\
	find_min_or_max.c\
	push_swap_utils.c\
	free_cmds.c\
	print_cmds.c\
	command_layout.c\
	error_check.c
SRCS = push_swap.c\
	align_less_than_3.c\
	align_more_than_4.c\
	proc_remains.c
BONUS_SRCS = checker.c\
	get_next_line.c\
	get_next_line_utils.c
SHARED_OBJS = $(SHARED_SRCS:.c=.o)
REG_OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
DEPS = $(SRCS:.c=.d) $(BONUS_SRCS:.c=.d) $(SHARED_SRCS:.c=.d)
NAME = push_swap
BONUS_NAME = checker

.PHONY: all
all: $(NAME)

$(NAME): $(REG_OBJS) $(SHARED_OBJS)
	$(MAKE) -C ./libft bonus
	$(CC) $(CFLAGS) libft/libft.a $(REG_OBJS) $(SHARED_OBJS) -o $(NAME)

.PHONY: bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(REG_OBJS) $(BONUS_OBJS) $(SHARED_OBJS)
	$(MAKE) -C ./libft bonus
	$(CC) $(CFLAGS) libft/libft.a $(REG_OBJS) $(SHARED_OBJS) -o $(NAME)
	$(CC) $(CFLAGS) libft/libft.a $(BONUS_OBJS) $(SHARED_OBJS) -o $(BONUS_NAME)

%.o: %.c
	${CC} ${CFLAGS} -c -MMD -MP -o $@ $<

-include $(DEPS)

.PHONY:clean
clean:
	$(MAKE) -C ./libft clean
	rm -f $(REG_OBJS) $(BONUS_OBJS) $(SHARED_OBJS) $(DEPS)

.PHONY: fclean
fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME) $(BONUS_NAME)

.PHONY: re
re: fclean all
