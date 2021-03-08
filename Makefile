
CHECKER_SRC = checker.c \
get_next_line.c \
get_next_line_utils.c \
stack_tools_0.c \
stack_tools_1.c \
stack_tools_2.c \
stack_tools_3.c \
stack_tools_4.c \
tools_0.c \
tools_1.c \
tools_2.c \
tools_3.c 

PUSH_SWAP_SRC = push_swap.c \
stack_tools_0.c \
stack_tools_1.c \
stack_tools_2.c \
stack_tools_3.c \
stack_tools_4.c \
tools_0.c \
tools_1.c \
tools_2.c \
tools_3.c \
tools_4.c 

NAME = name
CHECKER = checker
PUSH_SWAP = push_swap
WWW = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(CHECKER) $(PUSH_SWAP)

$(CHECKER):
	gcc $(WWW) $(CHECKER_SRC) -o $(CHECKER) -g

$(PUSH_SWAP):
	gcc $(WWW) $(PUSH_SWAP_SRC) -o $(PUSH_SWAP) -g

clean:
	rm -rf a.out *dSYM
fclean: clean
	rm -rf $(CHECKER) $(PUSH_SWAP)

re: fclean all

san:
	gcc $(WWW) $(CHECKER_SRC) -o $(CHECKER) -g -fsanitize=address
	gcc $(WWW) $(PUSH_SWAP_SRC) -o $(PUSH_SWAP) -g -fsanitize=address

deb:
	gcc $(WWW) $(CHECKER_SRC) -o $(CHECKER) -g -fsanitize=address -DDEBUG
	gcc $(WWW) $(PUSH_SWAP_SRC) -o $(PUSH_SWAP) -g -fsanitize=address -DDEBUG

.PHONY: all $(NAME) clean fclean re